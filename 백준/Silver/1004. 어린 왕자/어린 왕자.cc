#include <iostream>
#include <math.h>

using namespace std;

class Vector2
{
public:
	Vector2(int _x, int _y) : x(_x), y(_y) {}
	Vector2() : x(0), y(0) {}
	int x;
	int y;

	float static GetDistance(Vector2 pos1, Vector2 pos2)
	{
		return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		Vector2 startPos;
		Vector2 endPos;
		cin >> startPos.x;
		cin >> startPos.y;
		cin >> endPos.x;
		cin >> endPos.y;

		int planetCnt;
		cin >> planetCnt;

		int count = 0;
		for (int i = 0; i < planetCnt; ++i)
		{
			Vector2 planetPos;
			int radius;
			cin >> planetPos.x;
			cin >> planetPos.y;
			cin >> radius;

			bool isHaveStartPos = Vector2::GetDistance(startPos, planetPos) < radius;
			bool isHaveEndPos = Vector2::GetDistance(endPos, planetPos) < radius;

			if (isHaveStartPos ^ isHaveEndPos)
				++count;
		}
		cout << count << endl;
	}
}