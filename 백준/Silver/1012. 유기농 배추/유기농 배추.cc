#include <iostream>

using namespace std;

const int yDir[] = { 0, 1, 0, -1 };
const int xDir[] = { -1, 0, 1, 0 };

int M, N, K;

bool check(int x, int y, int arr[50][50], int checkArr[50][50])
{
	if (arr[y][x] == 0 || checkArr[y][x] == 1) return false;

	checkArr[y][x] = 1;

	for (int j = 0; j < 4; ++j)
	{
		if (y + yDir[j] < 0 || y + yDir[j] >= N ||
			x + xDir[j] < 0 || x + xDir[j] >= M)
			continue;
		check(x + xDir[j], y + yDir[j], arr, checkArr);
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
		int checkArr[50][50]{ 0, };
		int arr[50][50]{ 0, };
		cin >> M >> N >> K;

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
				if (check(x, y, arr, checkArr))
				{
					res++;
				}
			}
		}

		cout << res << endl;
	}
}