/* Напишите процедуру, заполняющую квадратный двумерный массив по
диагоналям. На побочной диагонали должны стоять наибольшие значения, на
соседних с ней - на единицу меньшие, и так далее - до угла, в котором должны
стоять единицы. */

#include <stdio.h>
using namespace std;

void diag (int** &a, int b)
{
	b--;

	int c = b, d = 0, k = 1;
	while (c >= d)
	{
		int x = d, y = d;

		while (x < c)
		{
			a[y][x] = k;
			k++, x++;
		};

		while (y < c)
		{
			a[y][x] = k;
			k--, y++;
		};

		while (x > d)
		{
			a[y][x] = k;
			k++, x--;
		};

		while (y > d)
		{
			a[y][x] = k;
			k--, y--;
		};

		d++, c--;
		k += 2;
	};

	if ((b % 2) == 0)
	{
		a[(b/2)][(b/2)] = (b+1);
	};
}

int main()
{
	int n;
	scanf("%d", &n);
	int** stradanie = new int* [n];
	for (int otchayanie = 0; otchayanie < n; otchayanie++)
	{
		*(stradanie+otchayanie) = new int [n];
	};

	int w = 2;
	if ((n / 10) > 0) {w+=2;};
	diag(stradanie, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
		    if (j == 0) {printf("%2d", stradanie[i][j]);}
			else {printf("%*d", w, stradanie[i][j]);};
		};
		printf("\n");
	};
}
