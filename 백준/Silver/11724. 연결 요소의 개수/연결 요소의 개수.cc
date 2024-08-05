#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class pos 
{
public :
	int x;
	int y;

	bool operator==(const pos& p)
	{
		return x == p.x || x == p.y || y == p.x || y == p.y;
	}
};

unordered_set<int> numSet;
unordered_map<int, unordered_set<int>> linkMap;

void addSet(int n)
{
	if (numSet.find(n) != numSet.end()) return;
	numSet.insert(n);
	for (int num : linkMap[n])
	{
		addSet(num);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, count = 0;
	cin >> N >> M;

	pos arr[1000];

	for (int i = 0; i < M; ++i)
	{
		int x, y; 
		cin >> x >> y;
		if (linkMap.find(x) == linkMap.end())
			linkMap.insert({ x, unordered_set<int>() });
		if (linkMap.find(y) == linkMap.end())
			linkMap.insert({ y, unordered_set<int>() });
		linkMap[x].insert(y);
		linkMap[y].insert(x);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (numSet.find(i) == numSet.end()) ++count;
		addSet(i);
	}
	cout << count;
}