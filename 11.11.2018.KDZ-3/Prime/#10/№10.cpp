#include <iostream>
using namespace std;

int chet(int* a, int b)
{
    int m = 0;
    for (int i = 0; i < b; i++)
    {
        if (((*(a + i)) % 2) == 0)
        {
            m += 1;
        };
    };
    return m;
}

void zachto(int* &c, int d)
{
    int r = chet(c, d);

    int* plagiat = new int[d - r];
    int k = 0;
    for (int i = 0; i < d; i++)
    {
        if (((*(c + i)) % 2) != 0)
        {
            *(plagiat + k) = *(c + i);
            k += 1;
        };
    };

    c = plagiat;
}

int main()
{
    int n;
    cin >> n;
    int*capital = new int[n];
    for (int i = 0; i < n; i++)
    {
       cin >> *(capital + i);
    };

    int f = chet(capital, n);
    zachto(capital, n);
    cout << '\n';

    for (int i = 0; i < (n - f); i++)
    {
        cout << *(capital + i) << " ";
    };
    delete[] capital;
}
