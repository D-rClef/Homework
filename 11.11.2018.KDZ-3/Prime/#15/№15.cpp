#include <stdio.h>

using namespace std;

void diag (int** &a, int b)
{
	b -= 1;

	int c = b, d = 0, k = 1;
	while (c >= d)
	{
		int x = d, y = d;

		while (x < c)
		{
			a[y][x] = k;
			k += 1;
			x += 1;
		};

		while (y < c)
		{
			a[y][x] = k;
			k -= 1;
			y += 1;
		};

		while (x > d)
		{
			a[y][x] = k;
			k += 1;
			x -= 1;
		};

		while (y > d)
		{
			a[y][x] = k;
			k -= 1;
			y -= 1;
		};

		d += 1;
		c -= 1;
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
