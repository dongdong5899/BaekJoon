#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	vector<long long> numVec;
	cin >> K >> N;

	for (int i = 0; i < K; ++i)
	{
		long long num;
		cin >> num;
		numVec.push_back(num);
	}

	sort(numVec.begin(), numVec.end());

	unsigned long long left = 0, right = numVec[K - 1], mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid == 0) break;
		unsigned long long count = 0;
		for (int i = 0; i < K; ++i)
			count += numVec[i] / mid;

		if (count < N) right = mid - 1;
		else left = mid + 1;
	}
	cout << right;
}