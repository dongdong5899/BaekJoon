#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> inputVec;
	set<int> numSet;
	unordered_map<int, int> numMap;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		inputVec.push_back(num);
		numSet.insert(num);
	}
	int idx = 0;
	for (int i : numSet)
	{
		if (numMap.find(i) == numMap.end())
		{
			numMap[i] = idx;
		}
		++idx;
	}

	for (int i = 0; i < N; i++)
	{
		cout << numMap[inputVec[i]] << " ";
	}
}