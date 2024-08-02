#include <iostream>

using namespace std;

int chessCheck(char chessMap[8][8], char map[50][50], int startX, int startY)
{
	int count = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (map[startY + i][startX + j] == chessMap[i][j])
			{
				++count;
			}
		}
	}
	return min(count, 64 - count);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char chessMap[8][8];
	bool isW = false;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			chessMap[i][j] = isW ? 'W' : 'B';
			isW = !isW;
		}
		isW = !isW;
	}

	int N, M;
	char map[50][50];
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	int minCount = 64;
	for (int i = 0; i <= N - 8; ++i)
	{
		for (int j = 0; j <= M - 8; ++j)
		{
			minCount = min(minCount, chessCheck(chessMap, map, j, i));
		}
	}
	cout << minCount;
}