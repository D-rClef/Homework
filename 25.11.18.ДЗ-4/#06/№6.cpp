/* Напишите программу, находящую все простые числа Ченя не превосходящие n. 
Программа должна работать не более чем за O(n*log log n) шагов. */

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool *Beelzebub = new bool[n + 3];
	int *Mefisto = new int[n + 3];
	for (int i = 2; i <= (n+2); i++)
        {
           Beelzebub[i] = 1;
           Mefisto[i] = 0;
        };

	for (int i = 2; i <= (n + 2); i++)
	{
		if (Beelzebub[i])
		{
			for (int j = i + i; j <= (n + 2); j += i)
			{
				Beelzebub[j] = 0;
				int bes = j;
				while ((bes % i) == 0)
                                {
                                    Mefisto[j]++;
                                    bes /= i;
                                    if (Mefisto[j] > 2) break;
                                };
			};
		};
	};

	for (int i = 2; i <= n; i++)
	{
		if ((Beelzebub[i]) && ((Beelzebub[i + 2]) || (Mefisto[i + 2] == 2)))
		{
			cout << i << " ";
		};
	};
}
