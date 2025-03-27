#include <iostream>
#include <map>

using namespace std;

int main()
{
	int c;
	cin >> c;

	for (int count = 0; count < c; count++)
	{
		int n;
		cin >> n;
		map<string, int> countMap;
		for (int i = 0; i < n; i++)
		{
			string name;
			string pos;
			cin >> name >> pos;
			if (countMap.find(pos) == countMap.end())
				countMap.insert({ pos , 1 });
			else
				countMap[pos]++;
		}

		int cnt = 1;
		for (pair<string, int> pair : countMap)
		{
			cnt *= (pair.second + 1);
		}
		cnt -= 1;

		cout << cnt << "\n";
	}
}