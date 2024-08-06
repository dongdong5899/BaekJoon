#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct absStruct
{
	bool operator()(const int& a, const int& b) const
	{
		int absA = abs(a);
		int absB = abs(b);
		return absA > absB || (absA == absB && a > b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	priority_queue<int, vector<int>, absStruct> queue;
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