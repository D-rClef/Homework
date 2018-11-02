#include <iostream>

using namespace std;

int chet(int* a, int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*(a+i) % 2) == 0)
        {
            m += 1;
        };
    };
    return m;
}

void boychet (int*a, int n)
{
    int d = chet(a, n), k = 1;

    while (k != 0)
    {
        int k = 0;
        for (int i = 0; i < (n-1); i++)
        {
          if (((*(a+i) % 2) == 0) && ((*(a+i+1) % 2) != 0))
          {
              swap(*(a+i),*(a+i+1));
              k += 1;
          };
        };
    };

    k = (n-1);
    int i = (d-1);
    while (i != k)
    {
        delete[] (a+k);
        k -= 1;
    };
    delete (a+i);
}

int main()
{
    int siz_e;
    cin >> siz_e;

    int* WTH = new int [siz_e];
    for (int i = 0; i < siz_e; i++)
    {
        cin >> *(WTH+i);
    };

    int t = chet(WTH, siz_e);
    boychet(WTH, siz_e);

    for (int i = 0; i < (siz_e - t); i++)
    {
        cout << *(WTH+i);
    };

    return 0;
}
