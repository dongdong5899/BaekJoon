#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	unordered_set<int> S;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (str == "all")
			for (int i = 1; i <= 20; ++i) S.insert(i);
		else if (str == "empty")
			S.clear();
		else
		{
			int x;
			cin >> x;

			if (str == "add")
				S.insert(x);
			else if (str == "remove")
				S.erase(x);
			else if (str == "check")
				cout << (S.find(x) == S.end() ? 0 : 1) << "\n";
			else if (str == "toggle")
				if (S.find(x) == S.end())
					S.insert(x);
				else
					S.erase(x);
		}
	}
}