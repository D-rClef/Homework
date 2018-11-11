/* ƒл€ структуры Date напишите оператор минус возвращающий, количество дней
прошедших между датами. */

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

    Date (const Date &A)
    {
      Day = A.Day;
      Month = A.Month;
      Year = A.Year;
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

    int dni ()
    {
        if (Month == 2)
        {
            if (visokos()) {return 29;}
            else {return 28;};
        }
        else
        {
            if (((Month <= 7) && (((Month % 2) != 0))) || ((Month >= 8) && ((Month % 2) == 0)))
                {return 31;}
            else {return 30;};
        };
    }

    int skolko_esho()
    {
        int p = 0;
        while (Month < 12)
        {
            p += dni();
            Month++;
        };
        while (Day <= 31)
        {
            p++;
            Day++;
        };

        return p;
    }

    int &operator - (Date &B)
    {
        int n = (skolko_esho() - B.skolko_esho()), p = 0;

        if (n < 0) {n = -n;};
        if (Year > B.Year)
        {
            while (B.Year < Year)
            {
                B.Year++;
                if (B.visokos()) {p += 366;}
                else {p += 365;};
            };
        }
        else
        {
            while (Year < B.Year)
            {
                Year++;
                if (visokos()) {p -= 366;}
                else {p -= 365;};
            };
        };

        B.Day = 0;
        B.Day += n;
        B.Day += p;
        if (B.Day < 0) {B.Day = (-B.Day);};

        return (B.Day);
    }
};

int main()
{
    Date First;
    Date Second;

    First.input();
    Second.input();
    cout << '\n';

    cout << (Second - First);

}

