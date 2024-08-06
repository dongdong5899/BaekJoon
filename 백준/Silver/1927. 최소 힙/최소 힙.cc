#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	priority_queue<int, vector<int>, greater<int>> queue;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num; 
		cin >> num;
		if (num == 0)
		{
			if (queue.empty()) cout << 0 << "\n";
			else
			{
				cout << queue.top() << "\n";
				queue.pop();
			}
		}
		else queue.push(num);
	}
}