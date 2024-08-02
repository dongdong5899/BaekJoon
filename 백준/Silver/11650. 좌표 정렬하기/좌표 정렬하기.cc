#include <iostream>
#include <set>

using namespace std;

struct pos
{
	int x;
	int y;

	bool operator()(const pos& p1, const pos& p2) const
	{
		return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	set<pos, pos> personSet;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		pos p{ x, y };
		personSet.insert(p);
	}

	for (pos p : personSet)
	{
		cout << p.x << " " << p.y << "\n";
	}
}