#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		string str;
		cin >> str;

		int sum = 0, combo = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'O')
			{
				++combo;
				sum += combo;
			}
			else
				combo = 0;
		}
		cout << sum << "\n";
	}
}