#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long num, leftNum = -1, rightNum = 0, digit = 0;
	cin >> num;

	while (num > 0)
	{
		--num;
		++leftNum;
		long long check = leftNum;
		digit = 0;
		while (check > 0)
		{
			if ((check % 10) == 6) ++digit;
			else break;
			check /= 10;
		}
		long long rightCnt = pow(10, digit) - 1;
		num -= rightCnt;
	}
	if (num <= 0)
	{
		rightNum = pow(10, digit) + num - 1;
	}
	for (int i = 0; i < 3; ++i)
	{
		if ((leftNum % 10) == 6) leftNum /= 10;
		else break;
	}


	cout << leftNum * (long long)pow(10, digit + 3) + 666 * (long long)pow(10, digit) + rightNum;
}