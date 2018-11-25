#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool* Asmodei = new bool [n + 1];
    Asmodei[0] = Asmodei[1] = 0;

    for (int i = 2; i <= (2*n + 1); i++)
    {
        Asmodei[i] = 1;
        for(int i = 2; i <= 2*n + 1; i++)
        {
            if (Asmodei[i])
            {
                for (int j = i + i; j <= (2*n + 1); j += i)
                {
                    Asmodei[j] = 0;
                };
            };
        };
    };

    for (int i = 2; i <= n; i++)
    {
        if ((Asmodei[i]) && (Asmodei[2*i + 1])) {cout << i << " ";};
    };
}
