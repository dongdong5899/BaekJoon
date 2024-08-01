#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;

	cin >> N;
	int left = 0, gen;
	bool flag = false;
	for (gen = 0; gen < N; ++gen)
	{
		int sumNum = gen;
		int num = gen;
		while (num != 0)
		{
			sumNum += num % 10;
			num /= 10;
		}
		if (sumNum == N)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << gen;
	}
	else
	{
		cout << 0;
	}
}