/* Напишите программу, вычисляющую произведение цифр целого числа, чётность
которых совпадает с чётностью последней цифры. */

#include <iostream>
using namespace std;

bool ch(int a)
{
	return ((a % 2) == 0);
}

int main()
{
	long long N, k, r, p = 1;
	cin >> N;

	k = (N % 10);
	r = k;

	while (N >= 1)
	{
		if (ch(r) == ch(k))
		{
			p *= r;
		};
		N /= 10;
		r = (N % 10);
	};
	cout << p;
}
