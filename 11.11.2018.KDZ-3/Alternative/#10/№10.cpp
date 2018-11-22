#include <stdio.h>
#include <cstdlib>
#include <conio.h>
//#include <stdlib.h>
#include <time.h>
#include "windows.h"

using namespace std;

void output(char **a, int b, int c)
{
	system("cls");
	int k = 1, l = 0;

	for (int i = -1; i < b; i++)
	{
		for (int j = -1; j < c; j++)
		{
		    if (i == -1)
            {
                if (l == 0) {printf("   ");}
                else
                    {printf("%2d", l);};

                if (l == c) {printf("\n");};
                l++;
            }
            else
            {
               if (j == -1)
                {
                    printf("%2d", k);
                    printf(" ");
                    k++;
                }
                else
                {
                    printf("%2c", a[i][j]);
                };
            };
        };
		printf("\n");
	};
}

void mining(char** &a_, int b, int c, int t, int &quantity, int first_x, int first_y)
{
    srand(time(0));
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < c; j++)
		{
		    if ((i == first_x) && (j == first_y)) continue;

			int k = rand() % 100 + 1;
			if (k <= t)
			{
				a_[i][j] = '*';
				quantity++;
			}
			else {a_[i][j] = '0';};
		};
	};
}

void mins_detector(char **&a_, int b, int c)
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a_[i][j] == '*')
				continue;

			int p = 0;
			int x = i, y = j;

			if (x > 0)
			{
				x -= 1;
			};
			if (y > 0)
			{
				y -= 1;
			};
			int x_ = x, y_ = y;
			while ((x_ <= (b - 1)) && ((x_ - i) <= 1))
			{
				while ((y_ <= (c - 1)) && ((y_ - j) <= 1))
				{
					if (a_[x_][y_] == '*')
					{
						p++;
					};
					y_++;
				};
				y_ = y;
				x_++;
			};

			a_[i][j] = p + '0';
		};
	};
}

void end_game(char** &a, char** a_, int b, int c)
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a_[i][j] == '*')
			{
				a[i][j] = a_[i][j];
			};
		};
	};
	output(a, b, c);
}

void test (char** &a, char** a_, int b, int c, int &usl, int quantity)
{
    usl = 0;

    for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((a_[i][j] == '*') && (a[i][j] == '*'))
			{
				end_game(a, a_, b, c);
				printf("%s", "\n You lose! :`( ");
				usl = -2;
			};

			if (usl == -1) break;

			if ((a_[i][j] != '*') && (a[i][j] == a_[i][j]))
            {
                usl++;
            };
		};
	};

	if (usl == ((b*c) - quantity))
    {
        end_game(a, a_, b, c);
        printf("%s", "\n You win! :) ");
        usl = -1;
    };
}

void flag(char **&a, int b, int c, int b_, int c_)
{
	if (a[b_][c_] == '#')
	{
		a[b_][c_] = '!';
	}
	else
    {
        if (a[b_][c_] == '!')
        {
            a[b_][c_] = '#';
        };
    };
}

void open_cell(char** &a, char** a_, int b, int c, int b_, int c_)
{
    if (a[b_][c_] != '#') {return;}
    else
    {
        a[b_][c_] = a_[b_][c_];
        if (a[b_][c_] == '0')
        {
            int b_n = (b_ - 1), c_n = (c_ - 1);

            while (b_n <= (b_ + 1))
            {
                c_n = c_ - 1;
                while (c_n <= (c_ + 1))
                {
                    if ((b_n >= 0) && (c_n >= 0) && (b_n < b) && (c_n < c))
                        {
                            open_cell(a, a_, b, c, b_n, c_n);
                        };
                    c_n++;
                };
                b_n++;
            };
        };
    };
}

void action(char** &a, char** a_, int b, int c, int &ha, int t, int &quantity)
{
    int ch, x, y;
    printf("%s%s%s", "Choose action: \n", "1. Open cell \n", "2. Set/remove flag \n");
    scanf("%d", &ch);
    printf("%s", "Choose coordinates (left, upper): \n");
    scanf("%d%d", &x, &y);
    x--, y--;

    if (ha == 0)
    {
        mining(a_, b, c, t, quantity, x, y);
        mins_detector(a_, b, c);
        ha++;
    };

    if (ch == 1) {open_cell(a, a_, b, c, x, y);};
    if (ch == 2) {flag(a, b, c, x, y);};

    output(a, b, c);
}

int main()
{
    int m, n, P, mine = 0, help, kostyl = 0;

    printf("%s", "Enter size: \n");
	scanf("%d%d", &m, &n);
	printf("%s", "Enter complexity in % (recommended is about 10-20%): \n");
	scanf("%d", &P);

	char **pole = new char *[m];
	for (int i = 0; i < m; i++)
	{
		*(pole + i) = new char[n];
	};

	char **pole_ten = new char *[m];
	for (int i = 0; i < m; i++)
	{
		*(pole_ten + i) = new char[n];
	};

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pole[i][j] = '#';
		};
	};

	output(pole, m, n);
	int safety = 0;

	while (0 == 0)
    {
        action(pole, pole_ten, m, n, kostyl, P, mine);
        test(pole, pole_ten, m, n, help, mine);

        if ((help != -1) && (help != -2))
        {
            char d;
            printf("%s", "Click ESC, if you want to finish game,\n or any other button, if you don't \n");
            d = getch();
            if (d == 27)
            {
                exit(0);
            };
        }
        else break;
    };
}
