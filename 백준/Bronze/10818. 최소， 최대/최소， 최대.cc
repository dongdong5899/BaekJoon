#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count, minN = 0, maxN = 0;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int num;
		cin >> num;
		if (i == 0)
		{
			minN = maxN = num;
			continue;
		}
		if (minN > num)
			minN = num;
		if (maxN < num)
			maxN = num;
	}

	cout << minN << " " << maxN;
}