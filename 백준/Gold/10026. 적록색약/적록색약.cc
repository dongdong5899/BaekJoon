#include <iostream>
#include <map>

using namespace std;

char colorArr[100][100];
bool arr[100][100] = { false, };

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int num;

int findZone(int x, int y, bool b)
{
	if (arr[y][x] ^ b) return 0;
	arr[y][x] = !b;
	char ch = colorArr[y][x];
	if (b && ch == 'G')
		ch = 'R';
	for (int i = 0; i < 4; i++)
	{
		int newX = x + dirX[i];
		int newY = y + dirY[i];
		char newCh = colorArr[newY][newX];
		if (b && newCh == 'G')
			newCh = 'R';
		if (newX >= 0 && newX < num && newY >= 0 && newY < num && 
			newCh == ch && arr[newY][newX] == b)
		{
			findZone(newX, newY, b);
		}
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> colorArr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cnt += findZone(j, i, false);
		}
	}
	cout << cnt << " ";

	cnt = 0;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cnt += findZone(j, i, true);
		}
	}
	cout << cnt;
}