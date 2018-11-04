#include <stdio.h>

using namespace std;

void pyramida(int **&a, int b)
{
	b -= 1;

	int c = b, d = 0, k = 1;
	while (c >= d)
	{
		int x = d, y = d;

		while (x < c)
		{
			a[y][x] = k;
			x += 1;
		};

		while (y < c)
		{
			a[y][x] = k;
			y += 1;
		};

		while (x > d)
		{
			a[y][x] = k;
			x -= 1;
		};

		while (y > d)
		{
			a[y][x] = k;
			y -= 1;
		};

		d += 1;
		c -= 1;
		k += 1;
	};

	if ((b % 2) == 0)
	{
		a[(b / 2)][(b / 2)] = ((b / 2) + 1);
	};
}

int main()
{
	int n;
	scanf("%d", &n);
	int **easy = new int *[n];
	for (int win = 0; win < n; win++)
	{
		*(easy + win) = new int[n];
	};

	pyramida(easy, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d", easy[i][j]);
		};
		printf("\n");
	};
}
