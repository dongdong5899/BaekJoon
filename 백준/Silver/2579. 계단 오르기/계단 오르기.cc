#include <iostream>

using namespace std;

int main()
{
	int stairs[300];
	int count = 0;
	cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		cin >> stairs[i];
	}

	int dp[300][2] = { { 0, 0 }, { 0, 0 }, };

	for (size_t i = 2; i < count + 2; i++)
	{
		dp[i][0] = dp[i - 1][1] + stairs[i - 2];
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + stairs[i - 2];
	}

	cout << max(dp[count + 1][0], dp[count + 1][1]);
}