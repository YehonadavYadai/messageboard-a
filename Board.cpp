#include <iostream>
#include "Board.hpp"
#include <math.h>
#include <vector>
using namespace std;

namespace ariel {

    const uint ten=10;
    void Board::resize(uint row, uint cow){ 
        this->rows=row;
        this->cols=cow; 
        
        //build new rows that all empty   
        this->board.resize(row+ten,vector<char>(cow,'_'));
        
        //resize the old rows to be bigger 
        for (ulong i = 0; i < row+ten; i++)
       {
          this->board.at(i).resize(cow+ten,'_');
          
       }
       this->rows=row+ten;
        this->cols=cow+ten;
    
    }

    void Board::post(uint row, uint col, Direction direction, string message) {
            uint size=message.length();
            uint limit_right=0;
            uint limit_down=0;
            



            if (direction==Direction::Horizontal){
                this->limit_down=min(this->limit_down,row);
                this->limit_up=max(this->limit_up, row);
                this->limit_left=min(this->limit_left,col);
                this->limit_right=max(this->limit_right,col+size);


                 limit_right=col+size;
                 limit_down=row;

                if (limit_down>this->rows||limit_right>this->cols)
                    {
                        resize(limit_down,limit_right);
                    }


                for(ulong i=0;i<size;i++)
                    {
                      
                        this->board.at(row).at(i+col)=message[i];
                        
                    }

            }

            else 
            {
                this->limit_down=min(this->limit_down,row);
                this->limit_up=max(this->limit_up, row+size);
                this->limit_left=min(this->limit_left,col);
                this->limit_right=max(this->limit_right,col);
                
                 limit_right=col;
                 limit_down=size+row;

                if (limit_down>this->rows||limit_right>this->cols)
                    {
                        this->resize(limit_down,limit_right);
                    }

                for(ulong i=0;i<size;i++)
                {
                     
                     this->board.at(row+i).at(col)=message[i];
                    //  std::cout<<message[i];
                
                }   
            }

            // this->limit_down=min(limit_down,this->rows);
            // this->limit_up=max(limit_right,this->cols);

    }



    string Board::read(uint row, uint col, Direction direction, uint length) 
    {
        string msg="";
        ulong i =0;
        // if is out of range send him empty msg
        if (row>=this->rows||col>=this->cols){
            for (ulong i = 0; i < length; i++)
            {
               
                msg.push_back('_');
            }
            return msg;
        }
        
        //if in range just read as is . 

        if (direction==Direction::Horizontal){
            

           
            i=col;
            while((i < col+length)&& (i<this->cols)){

                msg.push_back(this->board.at(row).at(i));
                i++;
            }

            //if the board ended so fill the rest of the len with '_'

            while(i>col+length)
            {
                cout<<"i added !!!!";
                msg.push_back('_');
                i++;
            }
            

            
            

        }

        else{
            i=row;
             while((i < row+length)&& (i<this->rows)){
                 
                msg.push_back(this->board.at(i).at(col));
                
                i++;
            }

            //if the board ended so fill the rest of the len with '_'

            while(i>row+length)
            {
                
                msg.push_back('_');
                i++;
            }

            
        }
        // cout<<this->limit_down<<endl;
        // cout<<this->limit_up<<endl;
        //  cout<<this->limit_left<<endl;
        //  cout<<this->limit_right<<endl;
        
        return msg;
        
    }

    void Board::show() 
    { 
        uint d = this->limit_down;
        uint u=this->limit_up;
        uint l = this->limit_left;
        uint r=this->limit_right;
        
        //if nothing posted break
        
        // if something post , show this 
        while (d<u)
        {
            cout<<"___";
            //print vector
            for (uint i = l; i < r; i++) 
            {
            std::cout << this->board.at(d).at(i) ;
            }   
            cout<<"___"<<endl<<endl;
            d++;
        }
    
        
    }

    }
