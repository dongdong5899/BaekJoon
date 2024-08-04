#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> numSet;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		numSet.push_back(num);
	}

	sort(numSet.begin(), numSet.end());

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; ++j)
		{
			sum += numSet[j];
		}
	}
	cout << sum;
}