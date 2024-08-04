#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, targetNum;
	stack<int> numSta1;
	stack<int> numSta2;
	stack<int> sortSta;
	cin >> N;
	targetNum = N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		numSta1.push(num);
	}

	int sum = 0;
	while (numSta1.empty() == false)
	{
		numSta2.push(numSta1.top());
		numSta1.pop();
		sortSta.push(-1);
		sum -= 1;
		while (numSta2.empty() == false && numSta2.top() == targetNum)
		{
			--targetNum;
			numSta2.pop();
			sortSta.push(1);
			sum += 1;
		}
	}

	if (sum != 0)
	{
		cout << "NO";
		return 0;
	}

	while (sortSta.empty() == false)
	{
		cout << (sortSta.top() == -1 ? '-' : '+') << "\n";
		sortSta.pop();
	}
}