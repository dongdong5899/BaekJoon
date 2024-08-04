#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, sum = 0;
	vector<int> numVec;
	unordered_map<int, int> numMap;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		numVec.push_back(num);
		if (numMap.find(num) == numMap.end())
			numMap.insert({ num, 0 });
		++numMap[num];
		sum += num;

	}

	sort(numVec.begin(), numVec.end());

	cout << (int)(round((float)sum / N)) << "\n";
	cout << numVec[N / 2] << "\n";
	int maxCount = 0;
	vector<int> maxCountNum;
	for (pair<int, int> num : numMap) maxCount = max(maxCount, num.second);
	for (pair<int, int> num : numMap)
	{
		if (maxCount == num.second)
			maxCountNum.push_back(num.first);
	}
	sort(maxCountNum.begin(), maxCountNum.end());
	cout << (maxCountNum.size() > 1 ? maxCountNum[1] : maxCountNum[0]) << "\n";
	cout << abs(numVec[0] - numVec[N - 1]) << "\n";
}