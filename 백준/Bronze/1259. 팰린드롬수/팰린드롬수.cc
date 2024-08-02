#include <iostream>

using namespace std;

#define charToint 96
#define r 31
#define M 1234567891

long long pow(int num, int power)
{
	long long res = 1;
	for (int i = 0; i < power; ++i)
	{
		res *= num;
		res %= 1234567891;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num = -1;
	int arr[5]{ 0, };
	
	while (true)
	{
		cin >> num;
		if (num == 0) break;
		int idx = 0;
		while (num > 0)
		{
			arr[idx++] = num % 10;
			num /= 10;
		}

		bool flag = true;
		for (int i = 0; i < idx / 2; i++)
		{
			if (arr[i] != arr[idx - 1 - i])
			{
				flag = false;
			}
		}

		cout << (flag ? "yes" : "no") << "\n";
	}
}