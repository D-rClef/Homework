#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    if (n >= 8) {k = 2*n;}
    else {k = 2*n + 3;};

    bool* resh = new bool[k];

    for(int i = 0; i < k; i++)
        {resh[i] = 0;};

    for (int i = 2; i < k; i++)
    {
        if (!resh[i])
        {
            for (int j = i+i; j < k; j += i)
            {
                resh[j] = 1;
            };
        };
    };

    for (int i = 0; i < k; i++)
    {
        if (n == 0) break;
        if (resh[i])
        {
            cout << i << " ";
            n--;
        };
    };
}
