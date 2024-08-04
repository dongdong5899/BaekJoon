#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	set<int> primeNum;
	cin >> M >> N;

	for (int i = 2; i <= N; ++i)
	{
		bool flag = false;
		for (int prime : primeNum)
		{
			if (prime > sqrt(i)) break;
			if (i % prime == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			primeNum.insert(i);
			if (i >= M) cout << i << "\n";
		}
	}
}