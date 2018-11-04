#include <stdio.h>
#include <cstdlib>

using namespace std;

void mining (int** &a, int b, int c, int t)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int k = rand() % 100 + 1;
            if (k <= t)
            {
                a[i][j] = -1;
            };
        };
    };
}


void mins_detector (int** &a, int b, int c)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == -1) continue;
            int p = 0;

            int x = i, y = j;

            if (x > 0) {x -= 1;};
            if (y > 0) {y -= 1;};
            int x_ = x, y_ = y;
            while ((x_ <= (b - 1)) && ((x_ - i) <= 1))
            {
                while ((y_ <= (c - 1)) && ((y_ - j) <= 1))
                {
                    if (a[x_][y_] == -1) {p++;};
                    y_++;
                };
                y_ = y;
                x_++;
            };

            a[i][j] = p;
        };
    };
}


int main()
{
    int m, n, P;
    scanf ("%d%d%d", &m, &n, &P);

    int** pole = new int* [m];
    for (int i = 0; i < m; i++)
	{
		*(pole+i) = new int [n];
	};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pole[i][j] = 0;
        };
    };

    mining(pole, m, n, P);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                printf("%2d", pole[i][j]);
            }
            else
            {
                printf("%4d", pole[i][j]);
            };
        };
        printf("\n");
    };

    printf("\n");

    mins_detector(pole, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                printf("%2d", pole[i][j]);
            }
            else
            {
                printf("%4d", pole[i][j]);
            };
        };
        printf("\n");
    };
}
