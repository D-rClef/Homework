#include <iostream>
using namespace std;

bool prost(int a)
{
	int k = 0;
	if (a == 1)
	{
		return (0==1);
	}
	else
	{
		for (int i = 2; i <= (a / 2); i++)
		{
			if ((a % i) == 0)
			{
				return (0 == 1);
				break;
				k += 1;
			};
		};
		if (k == 0)
		{
			return (1 == 1);
		};
	};
}

int main()
{
	int n, p = 0;
	cin >> n;
	int *zver = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> *(zver + i);
		if (prost(*(zver + i)) == prost(3))
		{
			p += *(zver + i);
		};
	};
	cout << '\n';
	cout << p;
}