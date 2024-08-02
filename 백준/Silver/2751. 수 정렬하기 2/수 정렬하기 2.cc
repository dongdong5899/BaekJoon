#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> numVec;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		numVec.push_back(num);
	}
	sort(numVec.begin(), numVec.end());

	for (int i = 0; i < N; ++i)
	{
		cout << numVec[i] << "\n";
	}
}