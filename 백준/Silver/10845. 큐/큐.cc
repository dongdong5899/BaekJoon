#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	queue<int> numQueue;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			numQueue.push(num);
			continue;
		}
		else if (str == "pop")
		{
			if (numQueue.empty())
				cout << -1;
			else
			{
				cout << numQueue.front();
				numQueue.pop();
			}
		}
		else if (str == "size")
			cout << numQueue.size();
		else if (str == "empty")
			cout << numQueue.empty() ? 1 : 0;
		else if (str == "front")
			cout << (numQueue.empty() ? -1 : numQueue.front());
		else if (str == "back")
			cout << (numQueue.empty() ? -1 : numQueue.back());
		cout << "\n";
	}
}