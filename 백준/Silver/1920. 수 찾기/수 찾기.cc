#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	unordered_set<long long> numSet;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		long long num;
		cin >> num;
		numSet.insert(num);
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		long long num;
		cin >> num;
		cout << (numSet.find(num) == numSet.end() ? 0 : 1) << "\n";
	}
}