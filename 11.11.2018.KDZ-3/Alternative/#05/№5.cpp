#include <iostream>
using namespace std;

long long last(long long x, long long y)
{
    x %= 10;
    long long m, a = x;
    long long P[5];
    P[0] = x;



    for(long long i = 1; i <= 5; i++)
    {
        a *= x;
        a %= 10;
        P[i] = a;
        if (a == x)
        {
            m = i;
            break;
        };
    };

    y %= m;

    if (m == 1)
    {
        return P[0];
    }
    else
    {
        if (y == 0)
        {
        return P[m-1];
        }
        else
        {
        y -= 1;
        return P[y];
        };
    };

}

int main()
{
    long long A, B;
    cin >> A >> B;
    cout << last(A,B);
}
