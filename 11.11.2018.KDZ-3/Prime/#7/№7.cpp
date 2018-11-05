#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *qwa = new int[n];

	for (int i = 0; i < n; i++)
	{
		int k = 0;
		cin >> *(qwa + i);

		int q = *(qwa + i);
		for (int j = 1; j <= *(qwa + i);  j++)
		{
			if ((q % j) == 0)
			{
				k++;
			};
		};
		if (k == 7)
		{
			cout << *(qwa + i) << " ";
		};
	};
}
