#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	stack<int> numStack;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			numStack.push(num);
			continue;
		}
		else if (str == "pop")
		{
			if (numStack.empty())
				cout << -1;
			else
			{
				cout << numStack.top();
				numStack.pop();
			}
		}
		else if (str == "top")
			cout << (numStack.empty() ? -1 : numStack.top());
		else if (str == "size")
			cout << numStack.size();
		else if (str == "empty")
			cout << numStack.empty() ? 1 : 0;
		cout << "\n";
	}
}