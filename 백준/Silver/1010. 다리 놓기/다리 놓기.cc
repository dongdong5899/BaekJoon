#include <iostream>
#include <math.h>

using namespace std;

int save[30][30]{ 0, };

long bridge(int start, int end, int level)
{
	if (level == 0) return 1;
	if (save[end - start][level] != 0) return save[end - start][level];

	int count = 0;
	for (int i = start; i <= end - level; i++)
	{
		count += bridge(i + 1, end, level - 1);
	}
	save[end - start][level] = count;
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{

		int N, M, res = 1;
		cin >> N >> M;

		res = bridge(0, M, N);

		cout << res << endl;
	}
}