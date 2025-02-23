<div dir="rtl" lang="he">

# לוח מודעות דו ממדי

בלוח המודעות השכונתי, אנשים מדביקים מודעות אחת על השניה, והמודעות מתערבבות ([כמו בסרטון הזה](https://www.youtube.com/watch?v=LgIq9BppBLw)).
במטלה זו נכתוב מחלקה לניהול לוח המודעות.
המחלקה צריכה לתמוך בפונקציות הבאות:

* `post` - מקבלת מיקום (שורה וטור), כיוון (אופקי או אנכי), ומחרוזת המייצגת מודעה, 
ומדביקה את המחרוזת על הלוח במקום המתאים.
* `read` - מקבלת מיקום (שורה וטור), כיוון (אופקי או אנכי), ומספר תוים, קוראת את מה שכתוב על הלוח במיקום הנתון ובאורך הנתון, ומחזירה מחרוזת. האות הנמצאת בכל משבצת על הלוח היא האות האחרונה שהודבקה שם.
* `show` - מציגה את לוח-המודעות הנוכחי בצורה נוחה לקריאה, בפורמט כלשהו לפי בחירתכם.

דוגמאות לפעולת המחלקה ניתן למצוא ב-[Demo.cpp](Demo.cpp).

פרטים:

* מספרי השורות והטורים ומספר התוים הם מספרים שלמים אי-שליליים (unsigned int).
* השורה העליונה היא 0 והטור השמאלי הוא 0.
* בכל משבצת שלא הודבק עליה כלום, יש קו תחתי
* גודל הלוח אינו מוגבל מראש, אבל אפשר להניח שכל המודעות יהיו מרוכזות באותו איזור -- המרחקים בין מודעה למודעה לא יהיו גדולים מאד.

רמזים:

* כדאי לתכנן ולחשוב על אלגוריתם יעיל לפני שמתחילים לממש.
* מומלץ לחזור על החומר שנלמד בהרצאות ולהשתמש בו.
* גם חומר שנלמד בקורס מבני נתונים יכול לעזור.


בשלב א עליכם לכתוב כותרות ובדיקות-יחידה מקיפות.
יש לבדוק את הפונקציות `post`, `read` בלבד;
אין צורך לבדוק את הפונקציה `show`
(כיוון שלא הגדרנו את הפורמט שלה).
כיתבו את כל הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

מומלץ גם להריץ:

<div dir='ltr'>

    make tidy
    make valgrind

</div>

שימו לב:
אין לשנות קבצים קיימים, אלא רק להוסיף קבצים חדשים.
מערכת הבדיקה האוטומטית מעתיקה מחדש את כל הקבצים הקיימים על-גבי הפתרון שאתם מגישים,
ולכן כל שינוי שתעשו בקבצים הקיימים יימחק.

בהצלחה
</div># board.cpp
# board.cpp
