#include <iostream>

using namespace std;

int prost(int l)
{
    int v = 0;
    if (l < 2)
    {
        return 0;
    }
    else
    {
       for (int j = 2; j <= (l/2); j++)
       {
          if ((l % j) == 0)
          {
              v += 1;
              return 0;
              break;
          };
       };
    };


    if (v == 0)
    {
        return 1;
    };
}


void NTI(int** OMG, int x, int y)
{
    int k = x*y;
    k -= 1;
    x -= 1;
    y -= 1;

    int q = 0;
    int* B = new int [k];

    while (q <= k);
    {
        for (int j = 4; 0 == 0; j++)
        {
            if (prost(j) == 0)
            {
                B[q] = j;
                q += 1;
            };
        };
    };

     q = 0;

     int w = x;
     int d = 0;

     int r = 0;
     int g = y;

     while (q <= k)
     {
         int e = d;
         int t = g;

         while (w > e)
         {
             OMG[w][r] = B[q];
             w -= 1;
             q += 1;
         };

         q += 1;
         w -= 1;

         while (r < t)
         {
             OMG[w][r] = B[q];
             r += 1;
             q += 1;
         };

         q += 1;
         r += 1;
         e = x;
         t = 0;

         while (w < e)
         {
             OMG[w][r] = B[q];
             w += 1;
             q += 1;
         };

         w += 1;
         q += 1;

         while (r > t)
         {
             OMG[w][r] = B[q];
             r -= 1;
             q += 1;
         };

         q += 1;
         w -= 1;
         d += 1;
         g -= 1;
     };
}




int main()
{
    int m, n;
    cin >> m >> n;

    m -= 1;
    n -= 1;

    int** F = new int* [m];
    for(int z = 0; z < m; z++)
    {
        F[z] = new int [n];
    };

    m += 1;
    n += 1;
    NTI(F, m, n);

    for(int z = 0; z < m; z++)
    {
        for(int c = 0; c < n; c++)
        {
            cout << F[z][c] << " ";
        };
    };
}
