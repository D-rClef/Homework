/* Для структуры Date напишите метод, находящий следующую дату-палиндром. */

#include <iostream>
using namespace std;

struct Date
{
    int Day;
    int Month;
    int Year;

    Date ()
    {
        Day = 0;
        Month = 0;
        Year = 0;
    }

    void input()
    {
        cin >> Day >> Month >> Year;
    }

    void output()
    {
        if ((Day / 10) == 0) {cout << 0;};
        cout << Day << ".";
        if ((Month / 10) == 0) {cout << 0;};
        cout << Month << "." << Year;
    }

    bool visokos()
    {
        if ((Year % 400) == 0) {return true;}
        else
            {
                if ((Year % 100) == 0) {return false;}
                else
                {
                    if ((Year % 4) == 0) {return true;}
                    else {return false;};
                };
            };
    }

    int dni()
    {
        if (Month == 2)
        {
            if (visokos()) {return 29;}
            else {return 28;};
        }
        else
        {
            if (((Month <= 7) && (((Month % 2) != 0))) || ((Month >= 8) && ((Month % 2) == 0)))
            {
                return 31;
            }
            else {return 30;};
        };
    }

    Date palindrom ()
    {
       int* kar = new int [8];
       int k = 0;

       while (k == 0)
       {
           int m = 0;
           kar[0] = (Day / 10);
           kar[1] = (Day % 10);
           kar[2] = (Month / 10);
           kar[3] = (Month % 10);
           kar[4] = (Year / 1000);
           kar[5] = ((Year / 100) % 10);
           kar[6] = ((Year / 10) % 10);
           kar[7] = (Year % 10);

           for (int i = 0; i <= 3; i++)
           {
               if (kar[i] != kar[7 - i]) break;
                m++;
           };

           if (m == 4) {break;}
           else
           {
               Day++;
               if (Day > dni())
               {
                   Day -= dni();
                   Month++;
               };
               if (Month > 12)
               {
                   Month -= 12;
                   Year++;
               };
           };
       };

       return *this;
    }
};

int main()
{
    Date nekr;
    nekr.input();

    nekr.palindrom();

    nekr.output();
}
