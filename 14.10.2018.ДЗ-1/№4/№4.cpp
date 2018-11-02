/*Напишите программу находящую в массиве сумму элементов делящихся либо
на 72 либо на 27(не вместе).*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int Tuturu[n];
    int i;
    int S = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>Tuturu[i];
    };

    for (int i = 0; i < n; i++)
    {
         if (((Tuturu[i] % 72) == 0) ^ ((Tuturu[i] % 27) == 0))
            {
                 S += Tuturu[i];
            };
    };

    cout<<S;

    return 0;
}
