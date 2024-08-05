#include <iostream>
#include <queue>

using namespace std;

int arr[128][128];

bool isSameColorRect(int x, int y, int width)
{
	bool flag = true;
	int color = arr[x][y];
	for (int i = x; i < x + width; ++i)
	{
		for (int j = y; j < y + width; ++j)
		{
			if (color != arr[i][j]) flag = false;
		}
	}
	return flag;
}

pair<int, int> counting(int x, int y, int width)
{
	if (width == 1 || isSameColorRect(x, y, width)) 
		return { (arr[x][y] + 1) % 2, arr[x][y] };

	int w = width / 2;
	int xint = counting(x, y, w).first + counting(x + w, y, w).first + counting(x, y + w, w).first + counting(x + w, y + w, w).first;
	int yint = counting(x, y, w).second + counting(x + w, y, w).second + counting(x, y + w, w).second + counting(x + w, y + w, w).second;
	return { xint, yint };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];
	cout << counting(0, 0, N).first << "\n" << counting(0, 0, N).second;
}