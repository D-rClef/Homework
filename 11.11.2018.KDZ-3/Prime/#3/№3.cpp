#include <iostream>
using namespace std;

long long C(int a, int b)
{
	if ((b < 1) || (a == b))
	{
		return 1;
	}
	else
	{
		return (C(a - 1, b - 1) + C(a - 1, b));
	};
}

int main()
{
	int n, k;
	cin >> n >> k;
	if (k > n)
	{
		cout << "What?";
	}
	else
	{
		cout << C(n, k);
	};
}