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

            if (j == 0)
            {
                if (i == 0)
                {
                    if (a[i][j+1] == -1) {p++;};
                    if (a[i+1][j] == -1) {p++;};
                    if (a[i+1][j+1] == -1) {p++;};
                }
                else
                {
                    if (i == (b - 1))
                    {
                        if (a[i-1][j] == -1) {p++;};
                        if (a[i-1][j+1] == - 1) {p++;};
                        if (a[i][j+1] == -1) {p++;};
                    }
                    else
                    {
                        if (a[i-1][j] == -1) {p++;};
                        if (a[i-1][j+1] == - 1) {p++;};
                        if (a[i][j+1] == -1) {p++;};
                        if (a[i+1][j] == -1) {p++;};
                        if (a[i+1][j+1] == -1) {p++;};
                    };
                };
            }
            else
            {
                if (j == (c - 1))
                {
                    if (i == 0)
                    {
                        if (a[i][j-1] == -1) {p++;};
                        if (a[i+1][j-1] == -1) {p++;};
                        if (a[i+1][j] == -1) {p++;};
                    }
                    else
                    {
                        if (i == (b - 1))
                        {
                            if (a[i-1][j-1] == -1) {p++;};
                            if (a[i-1][j] == -1) {p++;};
                            if (a[i][j-1] == -1) {p++;};
                        }
                        else
                        {
                            if (a[i-1][j-1] == -1) {p++;};
                            if (a[i-1][j] == -1) {p++;};
                            if (a[i][j-1] == -1) {p++;};
                            if (a[i+1][j-1] == -1) {p++;};
                            if (a[i+1][j] == -1) {p++;};
                        };
                    };
                }
                else
                {
                    if (i == 0)
                    {
                        if (a[i][j-1] == -1) {p++;};
                        if (a[i][j+1] == -1) {p++;};
                        if (a[i+1][j-1] == -1) {p++;};
                        if (a[i+1][j] == -1) {p++;};
                        if (a[i+1][j+1] == -1) {p++;};
                    }
                    else
                    {
                        if (i == (b - 1))
                        {
                            if (a[i-1][j-1] == -1) {p++;};
                            if (a[i-1][j] == -1) {p++;};
                            if (a[i-1][j+1] == - 1) {p++;};
                            if (a[i][j-1] == -1) {p++;};
                            if (a[i][j+1] == -1) {p++;};
                        }
                        else
                        {
                            if (a[i-1][j-1] == -1) {p++;};
                            if (a[i-1][j] == -1) {p++;};
                            if (a[i-1][j+1] == - 1) {p++;};
                            if (a[i][j-1] == -1) {p++;};
                            if (a[i][j+1] == -1) {p++;};
                            if (a[i+1][j-1] == -1) {p++;};
                            if (a[i+1][j] == -1) {p++;};
                            if (a[i+1][j+1] == -1) {p++;};
                        };
                    };
                };
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
