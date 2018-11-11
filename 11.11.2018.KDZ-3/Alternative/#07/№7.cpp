#include <stdio.h>
#include <cmath>
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

void NTI(int** &a, int b, int c)
{
    int q = (b*c), l = 0;
    int* sost = new int [q];
    while (l < q)
    {
        for (int j = 4; 0 == 0; j++)
        {
            if (prost(j) == 0)
            {
                sost[l] = j;
                l++;
                if (l == q) break;
            };
        };
    };
    l = 0;

    b--, c--;
	int d = 0, e = c;
	int f = b, g = 0;
	int x = d, y = f;

	bool usl;
	double B = b, C = c;
	B = (B/C);
	if (B < 1) {B = (C/B);};
	B = round(B);
	if (B >= 2)
    {
        usl = ((d <= e) && (f >= g));
    }
    else
    {
        usl = ((d <= e) || (f >= g));
    };

	while (usl)
	{
	    x = d;
		y = f;

		while (y > g)
		{
		    if (f <= g) break;
			a[y][x] = sost[l];
			l += 1;
			y -= 1;
		};

		while (x < e)
		{
		    if (d >= e) break;
			a[y][x] = sost[l];
			l += 1;
			x += 1;
		};

		while (y < f)
		{
		    if (f <= g) break;
			a[y][x] = sost[l];
			l += 1;
			y += 1;
		};

		while (x > d)
		{
		    if (d >= e) break;
			a[y][x] = sost[l];
			l += 1;
			x -= 1;
		};

		d++, e--, f--, g++;
		if (B >= 2)
        {
            usl = ((d <= e) && (f >= g));
        }
        else
        {
            usl = ((d <= e) || (f >= g));
        };

	};

	b++, c++;
	if (((b % 2) != 0) && ((c % 2) != 0))
    {
        a [(b - 1)/2] [(c - 1)/2] = sost[q - 2];
    };
}

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int** F = new int* [m];
    for(int z = 0; z < m; z++)
    {
        F[z] = new int [n];
    };

    int w = 3;
	if ((m*n) >= 10)
    {
        w += 2;
    };

    NTI(F, m, n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%*d", w, F [i][j]);
        };
        printf("\n");
    };
}
