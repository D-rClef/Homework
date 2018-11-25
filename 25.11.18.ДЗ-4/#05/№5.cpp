#include <iostream>

using namespace std;

void proizv (int* a, int b, int c)
{
    for (int i = 0; i < b; i++)
    {
        int copy_ = a[i], p = 1;

        while (a[i] >= 1)
        {
            if ((a[i] % 10) != 0) {p *= (a[i] % 10);};
            if (p > c)
            {
                cout << copy_ << " ";
                break;
            };
            *(a + i) /= 10;
        };
    };
}

int main()
{
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << '\n' << "Enter numbers " << '\n';

    int* Baal = new int [n];
    for(int i = 0; i < n; i++)
    {
        cin >> *(Baal + i);
    };

    cout << '\n' << "Enter k:" << '\n';
    cin >> k;
    cout << '\n' << "Result:" << '\n';
    proizv(Baal, n, k);
}
