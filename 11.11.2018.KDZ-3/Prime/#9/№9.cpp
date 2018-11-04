#include <iostream>

using namespace std;

bool sign(double a)
{
	return (a >= 0);
}

double f(double a)
{
	return (a * a * a - 3 * a + 7);
}

int main()
{
	double t, x = 0, c = 100, l = (x - c), r = (x + c);
	cin >> t;

	while (sign(f(l)) == sign(f(r)))
	{
		l -= c;
		r += c;
	};

	double d = (r - l);

	while ((f(x) != 0) && (sign(f(x - t)) == sign(f(x + t))))
	{
		d /= 2;
		if (sign(f(l)) != sign(f(x)))
		{
			r -= d;
			x -= (d / 2);
		}
		else
		{
			l += d;
			x += (d / 2);
		};
	};

	cout << x;
}
