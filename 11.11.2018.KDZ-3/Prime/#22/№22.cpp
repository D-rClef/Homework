#include <iostream>

using namespace std;

struct Date
{
    int Day;
    int Month;
    int Year;

    void input();
    void output();

    int skolko_esho(Date a)
    {
        int p = 0;
        while (a.Month <= 12)
        {
            if (a.Month == 2)
            {
                if ((a.Year % 400) == 0) {p += 29;}
                else
                {
                    if ((a.Year % 100) == 0) {p += 28;}
                    else
                    {
                        if ((a.Year % 4) == 0) {p += 29;}
                    };
                };
            }
            else
            {
                if (((a.Month <= 7) && (((a.Month % 2) != 0))) || ((a.Month >= 8) && ((a.Month % 2) == 0)))
                {
                    p += 31;
                }
                else {p += 30;};
            };
            a.Month += 1;
        };

        p -= a.Day;
        return p;
    }
};

void Date::input ()
{
    cin >> Day >> Month >> Year;
}

void Date::output ()
{
    cout << Day << Month << Year;
}

int main()
{
    Date Yo;
    Yo.input;
    Yo.output;
    cout << skolko_esho (Yo);
}
