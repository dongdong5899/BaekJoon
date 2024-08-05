#include <iostream>
#include<string>
#include <unordered_map>

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	unordered_map<int, string> numToName;
	unordered_map<string, int> nameToNum;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		string name;
		cin >> name;

		numToName.insert({ i, name });
		nameToNum.insert({ name, i });
	}

	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;
		if (str[0] < 65 && str[0] >= 48)
			cout << numToName[stoi(str)] << "\n";
		else
			cout << nameToNum[str] << "\n";
	}
}