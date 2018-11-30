#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    bool Behemot = 0;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << '\n' << 2 << '\n' << 3 << '\n' << 4 << '\n' << 5 << '\n' << 6 << '\n' << 7 << '\n' << 8 << '\n' << 9 << '\n';
        return 0;
    };

    if ((n % 2) == 1)
    {
        n--;
        Behemot = 1;
    };

    for (int i = pow(10, (n/2 - 1)); i < pow(10, (n/2)); i++)
    {
        int Astarot = i;
        if (Behemot)
        {
            for (int soul = 0; soul <= 9; soul++)
            {
                int tenn = Astarot;
                cout << Astarot;
                cout << soul;
                while (tenn >= 1) {cout << (tenn % 10); tenn /= 10;};
                cout << " ";
            };
        }
        else
        {
            int tenn = Astarot;
            cout << Astarot;
            while (tenn >= 1) {cout << (tenn % 10); tenn /= 10;};
            cout << " ";
        };
        cout << '\n';
    };

    return 0;
}
