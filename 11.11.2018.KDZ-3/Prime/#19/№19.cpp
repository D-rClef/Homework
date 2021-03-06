/* Напишите логическую функцию, проверяющую, является ли одна строка
анаграммой другой строки (т.е. может быть получена перестановкой букв). Можно
считать, что строка состоит только из букв латиницы. */

#include <iostream>
using namespace std;

int Length(char* a)
{
    int b = 0;
    while(*a++)
    {
        b++;
    };
    return b;
}

bool anagr(char* a, int b, char* c, int d)
{
    if (b != d)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < b; i++)
        {
            int u = 0;
            for (int j = 0; j < d; j++)
            {
                if (*(a + i) == *(c + j))
                {
                    int k = j, h = 0;
                    char* plagiat = new char [d - 1];
                    while (h < (d - 1))
                    {
                        for (j = 0; j < d; j++)
                        {
                            if (j != k)
                            {
                                *(plagiat + h) = *(c + j);
                                h++;
                            };
                        };
                    };
                    c = plagiat;
                    u++;
                };
            };
            if (u == 0)
            {
                return false;
                break;
            };
        };
        return true;
    };

}

int main()
{
    int n, m;

    char* izn = new char [256];
    cin.getline(izn, 256, '\n');
    n = Length(izn);

    char* whatisit = new char [256];
    cin.getline(whatisit, 256, '\n');
    m = Length(whatisit);

    cout << '\n';

    if (anagr(izn, n, whatisit, m) == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    };
}
