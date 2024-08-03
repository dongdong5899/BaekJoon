#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num[3];
	cin >> num[0] >> num[1] >> num[2];

	int sameCount = 0;
	int sameNum = 1;
	int maxNum = 0;
	for (int i = 0; i < 3; ++i)
	{
		int nextIdx = (i + 1) % 3;
		if (num[i] == num[nextIdx])
		{
			sameNum = num[i];
			++sameCount;
		}
		maxNum = max(maxNum, num[i]);
	}

	if (sameCount == 3)
		cout << 10000 + sameNum * 1000;
	else if (sameCount == 1)
		cout << 1000 + sameNum * 100;
	else
		cout << maxNum * 100;
}