#include <iostream>

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

    int i = 0;

    for (int j = 0; j < b; j++)
    {
        if (*(a + j) == ' ')
        {
            if (j == 0) continue;
            if (j == (b - 1)) continue;
            if (*(a + j + 1) == ' ') continue;
        };
        *(plagiat + i) == *(a + j);
        i++;
    };

    a = plagiat;
}

int main()
{
    int n;

    char* probel_zalipaet = new char [256];
    cin.getline(probel_zalipaet, 256, '\n');
    n = Length(probel_zalipaet);
    int y = lysh_prob(probel_zalipaet, n);

    uhodi(probel_zalipaet, n);

    n -= y;
    for (int i = 0; i < n; i++)
    {
        if (*(probel_zalipaet + i) != ' ')
        {
            cout << *(probel_zalipaet + i);
        }
        else
        {
            cout << " ";
        };
    };

}
