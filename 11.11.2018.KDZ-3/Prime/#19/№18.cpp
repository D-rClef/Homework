#include <iostream>

using namespace std;

int pal (char* A, int b)
{
    b -= 1;
    int k = 0;
    for (int i = 0; i <= ((b - 1)/2); i++)
    {
        if (A[i] != A[b - i])
        {
            k += 1;
        };
    };
    return (k == 0);;
}

int main()
{
    int n;
    cin >> n;
    char* Hmm = new char [n];

    for (int i = 0; i < n; i++)
    {
        cin >> Hmm[i];
    };

    cout << '\n';

    if (pal(Hmm, n) == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    };
}
