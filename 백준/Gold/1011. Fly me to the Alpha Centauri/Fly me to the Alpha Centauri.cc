#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{
		int res = 0;
		long x, y;
		cin >> x >> y;

		res = ceil(sqrt(y - x) * 2 - 1);
		cout << res << endl;
	}
}