/* Напишите процедуру, проводящую “разжатие” символьного динамически
выделенного массива, сделанное в прошлой задаче. Например строка “3a1b5c2d “
должна перейти в “aaabcccccdd”. Можно считать, что не бывает более девяти
одинаковых букв, идущих подряд. */

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

int Length(char* a)
{
    int b = 0;
    while(*a++)
    {
        b++;
    };
    return b;
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
            q--, z++;
        };
    };

    a = plagiat;
}

int main()
{
   int n;
   char* shifr = new char [256];
   cin.getline(shifr, 256, '\n');
   n = Length(shifr);

   int w = pamyat(shifr, n);
   antizip(shifr, n);

   for (int i = 0; i < w; i++)
   {
       cout << *(shifr + i);
   };
}
