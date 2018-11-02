#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k;
    long long p = 1;
    double n;
    cin >> n;

    int N = round(n);
    if (N <= 4)
    {
        cout << N;
    }
    else
    {
        k = round(sqrt(N));
        k -= 1;
        int* x = new int [k];

        for(int i = 0; i < k; i++)
        {
            x[i] = round(n/(k+1));
        };
        x[k] = N - (x[0]*k);

        if (x[k] > x[0])
        {
            int j = 0;
            while ((x[k] - x[0]) > 1)
            {
                x[k] -= 1;
                x[j] += 1;
                j +=1;
                if (j == k)
                {
                    j = 0;
                };
            };
        }
        else
        {
            int j = (k-1);
            while ((x[0] - x[k]) > 1)
            {
                x[k] += 1;
                x[j] -= 1;
                j -=1;
                if (j == 0)
                {
                    j = (k-1);
                };
            };
        };

        for (int i = 0; i <= k; i++)
        {
            p *= x[i];
        };
        cout << p;
    };
}
