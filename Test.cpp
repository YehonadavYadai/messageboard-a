#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace ariel;
using namespace std;

TEST_CASE("test post")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "paskal"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "siakem! "));
    CHECK_NOTHROW(board.post(0, 3, Direction::Vertical, "hhhhhhhhhhhhhhhhh"));
    CHECK_NOTHROW(board.post(5, 2, Direction::Horizontal, "32832382983298492"));
    CHECK_NOTHROW(board.post(5, 2, Direction::Vertical, "i need to do it "));
}
TEST_CASE("test of empty strings ")
{
    Board board;
    //at the start of the board
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    //somewhere at the board
    CHECK(board.read(9555, 2323, Direction::Horizontal, 0) == "");
    CHECK(board.read(264646, 23253, Direction::Vertical, 0) == "");
    //corners check
    CHECK(board.read(7, 1, Direction::Horizontal, 0) == "");
    CHECK(board.read(7, 1, Direction::Vertical, 0) == "");
    //out of the init default limits check
    CHECK(board.read(30, 44, Direction::Horizontal, 0) == "");
    CHECK(board.read(45, 402, Direction::Vertical, 0) == "");
}

TEST_CASE("check- single words")
{
    Board board;
    board.post(0, 0, Direction::Horizontal, "lebron");
    board.post(0, 3, Direction::Horizontal, "james");
    board.post(1, 0, Direction::Vertical, "kevin");
    board.post(7, 0, Direction::Vertical, "durant");
    board.post(10, 10, Direction::Horizontal, "james");
    board.post(11, 11, Direction::Vertical, "harden");

     CHECK(board.read(0, 0, Direction::Horizontal, 3) == "leb");
    CHECK(board.read(0, 3, Direction::Horizontal, 6) == "james_");
    CHECK(board.read(0, 1, Direction::Horizontal, 2) == "eb");
    CHECK(board.read(0, 0, Direction::Horizontal, 8) == "lebjames");
    CHECK(board.read(1, 0, Direction::Vertical, 5) == "kevin");
    CHECK(board.read(7, 0, Direction::Vertical, 10) == "durant____");
    CHECK(board.read(1, 0, Direction::Vertical, 15) == "kevin_durant___");
    CHECK(board.read(10, 10, Direction::Horizontal, 7) == "james__");
    CHECK(board.read(10, 13, Direction::Horizontal, 4) == "es__");
    CHECK(board.read(11, 11, Direction::Vertical, 8) == "harden__");
    CHECK(board.read(13, 11, Direction::Vertical, 6) == "rden__");

    CHECK(board.read(20, 20, Direction::Horizontal, 5) == "_____"); //empty space on board
}

TEST_CASE("check- multiple words")
{
    Board board;
    board.post(0, 0, Direction::Horizontal, "russle westbrook");
    board.post(1, 0, Direction::Vertical, "lamelo ball");

    CHECK(board.read(0, 0, Direction::Horizontal, 10) == "russle wes");
    CHECK(board.read(0, 0, Direction::Vertical, 16) == "rlamelo ball____");
    CHECK(board.read(0, 4, Direction::Horizontal, 6) == "le wes");  //partial reading
    CHECK(board.read(7, 0, Direction::Vertical, 9) == " ball____"); //partial reading
}
TEST_CASE("check  in Vertical to Horizontal")
{
    Board board;
    board.post(0, 0, Direction::Vertical, "adam silver rocks!");
    board.post(0, 2, Direction::Vertical, "michal jordan is goat ");

    CHECK(board.read(0, 0, Direction::Vertical, 3) == "ada");         //reading first line
    CHECK(board.read(1, 0, Direction::Vertical, 6) == "dam si");      //reading second line
    CHECK(board.read(2, 0, Direction::Vertical, 5) == "am si");       //reading first line
    CHECK(board.read(3, 0, Direction::Vertical, 10) == "m silver r"); //reading second line
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == "a_");        //reading Horizontal letters from vertical messages
    CHECK(board.read(3, 0, Direction::Horizontal, 2) == "m_");
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == "a_m_");
    CHECK(board.read(4, 0, Direction::Horizontal, 4) == " _a_");
}
TEST_CASE("multiple lines post and read cases-Horizontal to vertical")
{
    Board board;
    board.post(0, 0, Direction::Horizontal, "fade away!!");
    board.post(0, 2, Direction::Horizontal, "luka magic ! he did is again ! ");

    CHECK(board.read(0, 0, Direction::Horizontal, 3) == "fal");
    CHECK(board.read(1, 0, Direction::Horizontal, 6) == "______");
    CHECK(board.read(2, 0, Direction::Horizontal, 6) == "______");
    CHECK(board.read(0, 3, Direction::Horizontal, 10) == "uka magic ");
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == "falu");
    CHECK(board.read(0, 4, Direction::Vertical, 4) == "k___");
}
TEST_CASE("overriding posts - single line cases")
{
    Board board;
    board.post(0, 0, Direction::Horizontal, "blake grifin");
    board.post(0, 0, Direction::Horizontal, "jaret alen"); //partial overriding
    board.post(0, 10, Direction::Horizontal, "davis bertans");
    board.post(0, 9, Direction::Horizontal, "AD best defence of the year"); //full word overriding
    board.post(3, 0, Direction::Vertical, "steff curry");
    board.post(3, 0, Direction::Vertical, "bill simmons");
    board.post(10, 10, Direction::Horizontal, "skotie pipen");
    board.post(10, 10, Direction::Vertical, "pull ups is bad shot");                                 //full word overriding
    board.post(2, 0, Direction::Horizontal, "pass to deni you damm westbrook"); //overriding in multiple words message-Horizontal
    board.post(2, 11, Direction::Horizontal, "DEEP THREE!!!");
    board.post(11, 11, Direction::Vertical, "Its Dame Time! ");
    board.post(18, 11, Direction::Vertical, "P. j Tacker");

    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "jaret a");
    CHECK(board.read(0, 9, Direction::Horizontal, 10) == "A_________");
    CHECK(board.read(3, 0, Direction::Vertical, 11) == "bill simm__");
    CHECK(board.read(10, 10, Direction::Vertical, 4) == "pu__");
    CHECK(board.read(2, 0, Direction::Horizontal, 35) == "pass to denDEEP THREE");
    CHECK(board.read(11, 11, Direction::Vertical, 19) == "Its DamP. j Tacker_");
}
TEST_CASE("overriding posts - multiple lines cases")
{
    Board board;
    board.post(1, 0, Direction::Horizontal, "sakid bay best of rookies ! ");
    board.post(0, 0, Direction::Horizontal, "deni wont be the rookie of the year ");
    board.post(2, 1, Direction::Vertical, "faster triple double");
    board.post(2, 0, Direction::Vertical, "gordon contacrt his ok now ");

    CHECK(board.read(1, 0, Direction::Horizontal, 5) == "sakid");
    CHECK(board.read(2, 1, Direction::Vertical, 5) == "faste");
}




