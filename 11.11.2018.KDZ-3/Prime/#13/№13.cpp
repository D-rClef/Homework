#include <iostream>

using namespace std;

int variable (char* a, int b)
{
    int k = 1;
    for (int i = 0; i < (b-1); i++)
    {
        if ((*(a+i)) != (*(a+i+1)))
        {
            k += 1;
        };
    };
    return k;
}

void zip (char* &a, int b)
{
    int r = variable(a, b);
    r += r;
    int z = 0;
    char* plagiat = new char [r];
    int i = 0;
    while (i < b)
    {
        int v = 0;
        int j = i;
        while ((*(a+i)) == (*(a+j)))
        {
            v += 1;
            j += 1;
        };

        *(plagiat + z + 1) = *(a+i);
        *(plagiat + z) = v + '0';
        i = j;
        z += 2;
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

   int f = variable(shifr,n);
   f += f;
   zip(shifr, n);

   for (int i = 0; i < f; i++)
   {
       cout << *(shifr + i);
   };
}
