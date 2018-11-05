#include <iostream>

using namespace std;

int variable (char* a, int b)
{
    int k = 1;
    for (int i = 0; i < (b-1); i++)
    {
        if ((*(a+i)) != (*(a+i+1)))
        {
            k++;
        };
    };
    return k;
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
            v++;
            j++;
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

   char* shifr = new char [256];
   cin.getline(shifr, 256, '\n');
   n = Length(shifr);

   int f = variable(shifr,n);
   f += f;
   zip(shifr, n);

   for (int i = 0; i < f; i++)
   {
       cout << *(shifr + i);
   };
}
