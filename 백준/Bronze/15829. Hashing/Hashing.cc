#include <iostream>

using namespace std;

#define charToint 96

int pow(int num, int power)
{
	int res = 1;
	for (int i = 0; i < power; ++i)
	{
		res *= num;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const int r = 31, M = 1234567891;
	int L;
	char chars[51];
	cin >> L;
	cin >> chars;

	int sum = 0;
	for (int i = 0; i < L; ++i)
	{
		sum += (chars[i] - charToint) * pow(r, i);
		sum %= M;
	}

	cout << sum;
}