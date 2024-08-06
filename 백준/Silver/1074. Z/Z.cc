#include <iostream>
#include <math.h>

using namespace std;

int counting(int x, int y, int width, int rectX, int rectY)
{
	if (width == 1) return 0;
	int halfWidth = width / 2;
	int xPos = x >= halfWidth + rectX ? 1 : 0;
	int yPos = y >= halfWidth + rectY ? 1 : 0;
	return (xPos + yPos * 2) * pow(halfWidth, 2) +
		counting(x, y, halfWidth, rectX + xPos * halfWidth, rectY + yPos * halfWidth);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;
	cout << counting(c, r, pow(2, N), 0, 0);
}