#include <iostream>
#include <cmath>
using namespace std;

long long fact(unsigned int N)
{
    if ((N == 0))
    {
        return 1;
    }
    else
    {
        while ((N-1) != 0)
        {
            return (N*fact(N-1));
        };
    };
}

int main()
{
    unsigned int n;
    long long q, k, s = 0;
    cin >> n;
    q = fact(n);
    k = q % 10;

    while (q >= 1)
    {
        if (k == 0)
        {
            s += 1;
        };
        q /= 10;
        k = q % 10;
    };

    cout << s;
}
