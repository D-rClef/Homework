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

	diag(stradanie, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%3d", stradanie[i][j]);
		};
		printf("\n");
	};
}
