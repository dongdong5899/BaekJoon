#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{
		int a, b, res = 1;
		cin >> a >> b;

		b %= 4;
		if (b == 0) b = 4;

		for (int i = 0; i < b; ++i)
			res *= a;

		res %= 10;
		if (res == 0) res = 10;
		cout << res << endl;
	}
}