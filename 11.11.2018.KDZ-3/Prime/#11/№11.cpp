#include <iostream>

using namespace std;

int Max_a (int* a, int b)
{
    int k = *a;
    for (int i = 0; i < b; i++)
    {
        if ((*(a + i)) > k)
        {
            k = *(a+i);
        };
    };
    return k;
}

int min_a (int* a, int b)
{
    int k = *a;
    for (int i = 0; i < b; i++)
    {
        if ((*(a + i)) < k)
        {
            k = *(a+i);
        };
    };
    return k;
}

int skolko (int* a, int b)
{
    int m = 0;
    for (int i = 0; i < b; i++)
    {
        if (((*(a + i)) == (Max_a(a,b))) || ((*(a+i)) == (min_a(a,b))))
        {
            m += 1;
        };
    };
    return m;
}

void oioi(int* &a, int b)
{
    int r = skolko(a, b);
    int* plagiat = new int [b - r];
    int k = 0;

    for (int i = 0; i < b; i++)
    {
        if (((*(a + i)) != Max_a(a,b)) && ((*(a + i)) != min_a(a,b)))
        {
            *(plagiat + k) = *(a + i);
            k += 1;
        };
    };

    a = plagiat;
}

int main()
{
    int n;
    cin >> n;
    int* feya = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(feya + i);
    };

    int f = skolko(feya, n);
    oioi(feya, n);
    cout << '\n';

    for (int i = 0; i < (n - f); i++)
    {
        cout << *(feya+i) << " ";
    };

    delete[]feya;
}
