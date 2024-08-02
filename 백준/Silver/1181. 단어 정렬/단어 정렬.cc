#include <iostream>
#include <set>

using namespace std;

struct strSort
{
	bool operator()(const string& a, const string& b) const
	{
		return a.length() < b.length() || (a.length() == b.length() && a < b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	set<string, strSort> strSet;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		strSet.insert(str);
	}

	for (string str : strSet)
	{
		cout << str << "\n";
	}
}