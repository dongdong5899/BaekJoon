#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int H, W, N;
		cin >> H >> W >> N;

		int height = N % H;
		if (height == 0) height = H;

		int roomNum = ceil((float)N / H);

		cout << height;
		cout.width(2);
		cout.fill('0');
		cout << roomNum << "\n";
	}
}