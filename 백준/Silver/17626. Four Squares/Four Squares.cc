#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int min = 4;
	for (int i = 0; i <= sqrt(n); i++)
	{
		int value_1 = pow(i, 2);
		if (value_1 == n && min > 1)
			min = 1;
		if (value_1 >= n)
			break;
		for (int j = 0; j <= i; j++)
		{
			int value_2 = value_1 + pow(j, 2);
			if (value_2 == n && min > 2)
				min = 2;
			if (value_2 >= n)
				break;
			for (int k = 0; k <= j; k++)
			{
				int value_3 = value_2 + pow(k, 2);
				if (value_3 == n && min > 3)
					min = 3;
				if (value_3 >= n)
					break;
			}
		}
	}

	cout << min;
}