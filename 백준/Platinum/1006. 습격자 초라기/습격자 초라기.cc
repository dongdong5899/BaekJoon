#include <iostream>

using namespace std;

int N;
int W;
int** unitCount;

void Count(int** enemyCount, int set_1, int set_2)
{
	unitCount[1][0] = set_1;
	unitCount[1][1] = unitCount[1][2] = set_2;
	for (int i = 2; i < N + 1; ++i)
	{
		int vertical = enemyCount[0][i] + enemyCount[1][i] <= W ? 1 : 2;
		int upper = enemyCount[0][i] + enemyCount[0][i - 1] <= W ? 1 : 2;
		int lower = enemyCount[1][i] + enemyCount[1][i - 1] <= W ? 1 : 2;

		unitCount[i][0] = min(min(unitCount[i - 1][0] + vertical, unitCount[i - 1][1] + lower + 1), min(unitCount[i - 1][2] + upper + 1, unitCount[i - 2][0] + upper + lower));
		unitCount[i][1] = min(unitCount[i - 1][2] + upper, unitCount[i - 1][0] + 1);
		unitCount[i][2] = min(unitCount[i - 1][1] + lower, unitCount[i - 1][0] + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{
		int** enemyCount;
		cin >> N >> W;

		unitCount = new int*[N + 1];
		for (int i = 0; i <= N; i++)
		{
			unitCount[i] = new int[3] {0, };
		}
		enemyCount = new int*[2];
		for (int i = 0; i < 2; ++i)
		{
			enemyCount[i] = new int[N + 1] {0, };
			for (int j = 1; j <= N; ++j)
			{
				cin >> enemyCount[i][j];
			}
		}


		int temp_1 = enemyCount[0][1];
		int temp_2 = enemyCount[1][1];
		int res = 2 * N;

		if (N == 1) 
		{
			res = enemyCount[0][1] + enemyCount[1][1] <= W ? 1 : 2;
			cout << res << endl;
			continue;
		}

		Count(enemyCount, enemyCount[0][1] + enemyCount[1][1] <= W ? 1 : 2, 1);
		res = min(res, unitCount[N][0]);

		if (enemyCount[0][1] + enemyCount[0][N] <= W)
		{
			enemyCount[0][1] = W;
			Count(enemyCount, 2, 1);
			res = min(res, unitCount[N][2]);
			enemyCount[0][1] = temp_1;
		}

		if (enemyCount[1][1] + enemyCount[1][N] <= W)
		{
			enemyCount[1][1] = W;
			Count(enemyCount, 2, 1);
			res = min(res, unitCount[N][1]);
			enemyCount[1][1] = temp_2;
		}

		if (enemyCount[1][1] + enemyCount[1][N] <= W && enemyCount[0][1] + enemyCount[0][N] <= W)
		{
			enemyCount[1][1] = W;
			enemyCount[0][1] = W;
			Count(enemyCount, 2, 1);
			res = min(res, unitCount[N - 1][0]);
		}

		cout << res << endl;
	}
}

