#include <iostream>
#include <set>

using namespace std;

struct pos
{
	int x;
	int y;

	bool operator()(const pos& p1, const pos& p2) const
	{
		return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, count = 0;
	set<pos, pos> posSet;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		pos p{ x, y };
		posSet.insert(p);
	}

	for (pos p : posSet)
	{
		cout << p.x << " " << p.y << "\n";
	}
}