#include <iostream>
#include <unordered_set>

using namespace std;

pair<int, int>* arr;
unordered_set<int> numSet;

int counting(int num, int M)
{
	int res = 0;
	if (numSet.find(num) == numSet.end())
	{
		++res;
		numSet.insert(num);
		for (int i = 0; i < M; ++i)
		{
			if (arr[i].first == num)
			{
				res += counting(arr[i].second, M);
			}
			else if (arr[i].second == num)
			{
				res += counting(arr[i].first, M);
			}
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	arr = new pair<int, int>[M];

	for (int i = 0; i < M; ++i)
	{
		int x, y;
		cin >> x >> y;
		arr[i] = { x, y };
	}

	cout << counting(1, M) - 1;
}