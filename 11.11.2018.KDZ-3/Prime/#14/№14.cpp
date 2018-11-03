#include <iostream>

using namespace std;

int pamyat(char* a, int b)
{
    int p = 0, k;
    for (int i = 0; i < b; i++)
    {
        if ((i % 2) == 0)
        {
            k = (*(a + i) - '0');
            p += k;
        };
    };
    return p;
}

void antizip (char* &a, int b)
{
    int r = pamyat(a, b);
    char* plagiat = new char [r];
    int q, z = 0;;

    for (int i = 0; i < b; i += 2)
    {
        q = (*(a + i) - '0');
        while (q != 0)
        {
            *(plagiat + z) = *(a + i + 1);
            q -= 1;
            z += 1;
        };
    };

    a = plagiat;
}

int main()
{
   int n;
   cin >> n;
   char* shifr = new char [n];
   for (int i = 0; i < n; i++)
   {
       cin >> *(shifr + i);
   };

   int w = pamyat(shifr, n);
   antizip(shifr, n);

   for (int i = 0; i < w; i++)
   {
       cout << *(shifr + i);
   };
}
