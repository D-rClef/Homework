#include <iostream>

using namespace std;

int quant (int* a, int b, int c)
{
    int vse_dva = 0;
    for (int i = 0; i < b; i++)
    {
        int dva = 0, kar = a[i];
        while (kar > 1)
        {
            if ((kar % 3) == 2) {dva++;};
            kar /= 3;
        };
        if (dva < c) {cout << a[i] << " ";};
        vse_dva += dva;
    };
    cout << '\n';
    return vse_dva;
}

int main()
{
    int n, k;
    cin >>  n >> k;

    int* Belial = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> Belial[i];
    };

    cout << quant(Belial, n, k);
}
