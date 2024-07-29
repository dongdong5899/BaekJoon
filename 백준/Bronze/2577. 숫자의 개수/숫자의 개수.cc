#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, mul, countArr[10]{ 0, };
	cin >> a >> b >> c;
	mul = a * b * c;

	while (mul > 0)
	{
		++countArr[mul % 10];
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << countArr[i] << "\n";
	}
}