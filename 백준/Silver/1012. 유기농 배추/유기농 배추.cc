#include <iostream>
#include <unordered_set>

using namespace std;


const int yDir[] = { 0, 1, 0, -1 };
const int xDir[] = { -1, 0, 1, 0 };

int M, N, K;
int** arr;
unordered_set<int> checkSet;

bool check(int x, int y)
{
	int pos = 100 * x + y;
	if (checkSet.find(pos) != checkSet.end()) return false;
	checkSet.insert(pos);

	for (int j = 0; j < 4; ++j)
	{
		if (y + yDir[j] < 0 || y + yDir[j] >= N ||
			x + xDir[j] < 0 || x + xDir[j] >= M)
			continue;
		if (arr[y + yDir[j]][x + xDir[j]] == 1)
			check(x + xDir[j], y + yDir[j]);
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{
		int res = 0;
		cin >> M >> N >> K;
		checkSet.clear();
		arr = new int* [N];
		for (int i = 0; i < N; ++i)
		{
			arr[i] = new int[M] { 0, };
		}

		for (int i = 0; i < K; ++i)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;

		}

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				if (arr[y][x] == 0) continue;

				if (check(x, y))
				{
					res += 1;
				}
			}
		}

		cout << res << endl;
	}
}