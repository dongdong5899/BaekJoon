#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> numSet;
unordered_set<int>* linkMap;

void addSet(int n)
{
	numSet.insert(n);
	for (int num : linkMap[n])
	{
		if (numSet.find(num) != numSet.end()) continue;
		addSet(num);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, count = 0;
	cin >> N >> M;
	linkMap = new unordered_set<int>[N + 1];

	for (int i = 0; i < M; ++i)
	{
		int x, y; 
		cin >> x >> y;
		linkMap[x].insert(y);
		linkMap[y].insert(x);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (numSet.find(i) != numSet.end()) continue;
		++count;
		addSet(i);
	}
	cout << count;
}