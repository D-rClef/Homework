/* Для структуры Date:
 - напишите метод, выписывающий наименование дня недели по дате;
 - напишите метод, определяющий, сколько дней осталось до Нового Года;
 - напишите оператор минус возвращающий, количество дней прошедших между датами;
 - напишите оператор плюс, принимающий целое число дней и возвращающий дату, отстоящую на это количество дней;
 - напишите метод, находящий следующую дату-палиндром. */

#include <iostream>
#include <locale>
using namespace std;

int max_del_na (int a, int b)
{
    int m = 0;
    for (int i = a; i > 1; i--)
    {
        if ((i % b) == 0)
        {
            m = i;
            break;
        };
    };
    return m;
}

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

    int cod_mes ()
    {
        if ((Month == 1) || (Month == 10)) {return 0;};
        if (Month == 5) {return 1;};
        if (Month == 8) {return 2;};
        if ((Month == 2) || (Month == 3) || (Month == 11)) {return 3;};
        if (Month == 6) {return 4;};
        if ((Month == 9) || (Month == 12)) {return 5;};
        if ((Month == 4) || (Month == 7)) {return 6;};
    }

    int cod_year ()
    {
        int n = (Year / 100);
        n -= max_del_na(n, 4);
        n *= 5;
        n -= max_del_na(n, 7);
        return n;
    }


    int den_ned ()
    {
        int m = Day + cod_mes();
        m -= max_del_na(m, 7);

        int p = (Year % 100);
        p -= max_del_na(p, 28);
        p += ((Year % 100)/4);
        p += cod_year();
        if (((Month == 1) || (Month == 2)) && (visokos() == 1)) {p--;};

        m += p;
        m -= max_del_na(m, 7);

        return m;
    }

    int skolko_esho()
    {
        int a = Day, b = Month, c = Year;
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

        Day = a;
        Month = b;
        Year = c;

        return p;
    }

    int &operator - (Date &B)
    {
        int a = Day, b = Month, c = Year;
        int n = (skolko_esho() - B.skolko_esho()), p = 0;

        if (Year > B.Year)
        {
            while (B.Year < Year)
            {
                B.Year++;
                if (B.visokos()) {p -= 366;}
                else {p -= 365;};
            };
        }
        else
        {
            while (Year < B.Year)
            {
                Year++;
                if (visokos()) {p += 366;}
                else {p += 365;};
            };
        };

        B.Day = 0;
        B.Day += n;
        B.Day += p;
        if (B.Day < 0) {B.Day = (-B.Day);};

        Day = a;
        Month = b;
        Year = c;

        return (B.Day);
    }

    Date &operator + (int a)
    {
        Day += a;

        while (Day > dni())
        {
            Day -= dni();
            Month++;
        };

        while (Month > 12)
        {
            Month -= 12;
            Year++;
        };
        return *this;
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
    setlocale(LC_ALL, "Russian");

    Date D;
    cout << "Введите интересующую дату: ";
    D.input();

    cout << "День недели: ";
    if (D.den_ned() == 1) {cout << "Воскресенье";};
    if (D.den_ned() == 2) {cout << "Суббота";};
    if (D.den_ned() == 3) {cout << "Пятница";};
    if (D.den_ned() == 4) {cout << "Четверг";};
    if (D.den_ned() == 5) {cout << "Среда";};
    if (D.den_ned() == 6) {cout << "Вторник";};
    if ((D.den_ned() == 0) || (D.den_ned() == 7)) {cout << "Понедеьник";};
    cout << '\n';

    cout << "А новый год через " << D.skolko_esho() << " день (я/ей)" << '\n';

    Date Second;
    cout << "Введите вторую дату: ";
    Second.input();
    cout << "Между ними " << (D - Second) << " день (я/ей)" << '\n';

    int n;
    cout << "Введите количество дней, на которое хотите переместится от первой даты: ";
    cin >> n;
    D + n;
    cout << "Вы попали в ";
    D.output();
    cout << '\n';

    cout << "������, ��������� � ����� ��� ����-���������: ";
    D.palindrom();
    D.output();
}
