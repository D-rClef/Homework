#include <iostream>
using namespace std;
int prime(bool *a, int b)
{
    int p = 1;
    a[0] = a[1] = 0;
    for (int i = 2; i <= b; i++)
    {
        a[i] = 1;
        for (int i = 2; i <= b; i++)
        {
            if (a[i])
            {
                for (int j = i + i; j <= b; j += i) {a[j] = 0;};
            };
        };

        if (a[i] == 1) {p *= i;};
    };

    return p;
}
int main()
{
    int n;
    cin >> n;
    bool *do_ch = new bool[n + 1];
    cout << prime(do_ch, n);
}
