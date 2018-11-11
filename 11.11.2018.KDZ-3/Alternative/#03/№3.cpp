/* Сверхпростым числом будем называть такое простое число, что его номер в последовательности простых чисел – тоже прост. 
Напишите программу, находящую k-ое сверхпростое число. */

#include <iostream>
using namespace std;

int prost(int l)
{
    int v = 0;
    if (l < 2)
    {
        return 0;
    }
    else
    {
       for (int j = 2; j <= (l/2); j++)
       {
          if ((l % j) == 0)
          {
              v += 1;
              return 0;
              break;
          };
       };
    };


    if (v == 0)
    {
        return 1;
    };
}

int main()
{
    int k, i = 0, m = 0, q = 0;

    cin >> k;

    while (q < k)
    {
        i += 1;
        if (prost(i) == 1)
        {
            m += 1;
            if (prost(m) == 1)
            {
                q += 1;
            };
        };
    };
    cout << i;
}
