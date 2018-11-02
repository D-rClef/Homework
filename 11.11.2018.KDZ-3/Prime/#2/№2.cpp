#include <iostream>
using namespace std;

bool ch(int a)
{
	return ((a % 2) == 0);
}

int main()
{
	int N, k, r, p = 1;
	cin >> N;
	if (N < 10)
	{
		cout << N;
	}
	else
	{
		k = (N % 10);
		r = k;
		N /= 10;
		while (N >= 1)
		{
			if (ch(r) == ch(k))
			{
				p *= r;
			};
			r = (N % 10);
			N /= 10;
		};
		cout << p;
	};
}