#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int H, W;
	cin >> H >> W;
	int R, C, D;
	cin >> R >> C >> D;

	bool visited[64][64] = { false, };
	int arr[64][64][2];
	int xDir[4] = { 0, 1, 0, -1 };
	int yDir[4] = { -1, 0, 1, 0 };

	for (int i = 0; i < H; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < W; ++j)
		{
			arr[i][j][0] = str[j] - '0';
		}
	}
	for (int i = 0; i < H; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < W; ++j)
		{
			arr[i][j][1] = str[j] - '0';
		}
	}

	int x = C;
	int y = R;
	int d = D;
	int count = 0;
	int last = 0;
	while (x < W && x >= 0 && y < H && y >= 0 && count - last < 64 * 64 * 4)
	{
		count++;
		if (visited[y][x] == false)
		{
			visited[y][x] = true;
			last = count;
			d += arr[y][x][0];
		}
		else
		{
			d += arr[y][x][1];
		}
		if (d > 3) d -= 4;

		x += xDir[d];
		y += yDir[d];
	}
	cout << last;
}