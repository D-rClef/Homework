#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int lysh_prob (char* a, int b)
{
    int p = 0;

    for (int i = 0; i < b; i++)
    {
        if (*(a + i) == ' ')
        {
            if (i == 0)
            {
                p++;
            }
            else
            {
                if (i == (b - 1))
                {
                    p++;
                }
                else
                {
                    if (*(a + i + 1) == ' ')
                    {
                        p++;
                    };
                };
            };
        };
    };
    return p;
}

int Length(char* a)
{
    int b = 0;
    while(*a++)
    {
        b++;
    };
    return b;
}

 void uhodi (char* &a, int b)
{
    int r = lysh_prob(a, b);
    int k = (b - r);
    char* plagiat = new char [k];

    int i = 0, j = 0;;
    while (j < b)
    {
        if (i == k) break;
        if ((*(a + j)) != ' ')
        {
            *(plagiat + i) = *(a + j);
            i++;
        }
        else
        {
            if (j != 0)
            {
                if (*(a + j - 1) != ' ')
                {
                    *(plagiat + i) = *(a + j);
                    i++;
                };
            };
        };
        j++;
    };

    a = plagiat;
}

int main()
{
    int n;

    char* probel_zalipaet = new char [256];
    gets(probel_zalipaet);
    n = Length(probel_zalipaet);
    int y = lysh_prob(probel_zalipaet, n);

    uhodi(probel_zalipaet, n);

    int i = 0;
    while (i < (n - y))
    {
        if (*(probel_zalipaet + i) != ' ') {cout << *(probel_zalipaet + i);};
        if (*(probel_zalipaet + i) == ' ') {cout << " ";};
        i++;
    };
}
