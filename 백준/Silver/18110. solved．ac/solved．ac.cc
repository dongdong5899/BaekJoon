#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cut = 0, sum = 0;
	vector<int> difVec;
	cin >> N;
	cut = round((N * 15.0f) / 100);
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		difVec.push_back(num);
	}

	sort(difVec.begin(), difVec.end());

	for (int i = cut; i < N - cut; ++i)
	{
		sum += difVec[i];
	}
	if (sum == 0) cout << 0;
	else cout << round((float)sum / (N - 2 * cut));
}