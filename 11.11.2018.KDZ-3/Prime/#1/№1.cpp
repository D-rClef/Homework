#include <iostream>

using namespace std;

int main()
{
    long long n, k, s = 0;

    cin >> n;
    k = n % 10;

    while (k >= 1)
    {
        if ((k % 2) == 1)
        {
            s += k;
        };
        n /= 10;
        k = n % 10;
    };

    cout << s;
}
