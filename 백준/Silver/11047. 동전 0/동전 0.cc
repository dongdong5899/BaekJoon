#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, count = 0;
	vector<int> numVec;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int num; 
		cin >> num;
		numVec.push_back(num);
	}

	sort(numVec.begin(), numVec.end());

	for (int i = N - 1; i >= 0; --i)
	{
		if (K == 0) break;
		while (K >= numVec[i])
		{
			K -= numVec[i];
			++count;
		}
	}
	cout << count;
}