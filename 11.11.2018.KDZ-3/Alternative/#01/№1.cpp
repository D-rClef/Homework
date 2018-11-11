#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c = 1;
    for (int i = 2; i <= b; i++)
    {
        if (((a % i) == 0) && ((b % i) == 0))
        {
            c = i;
        };
    };
    return c;
}


int e(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        if (gcd(n,k) == 1)
        {
            return (1 + e(n-1, k));
        }
        else
        {
            return e(n-1, k);
        };
    };
}


int e(int n)
{
    return e(n,n);
}


int main()
{
    int x;
    cin >> x;
    cout << e(x);
}
