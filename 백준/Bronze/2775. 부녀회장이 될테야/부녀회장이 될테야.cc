#include <iostream>

using namespace std;

int personnel(int floor, int number)
{
	if (floor == 0) return number;
	int sum = 0;
	for (int i = 1; i <= number; ++i)
	{
		sum += personnel(floor - 1, i);
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int k, n;
		cin >> k >> n;
		cout << personnel(k, n) << "\n";
	}
}