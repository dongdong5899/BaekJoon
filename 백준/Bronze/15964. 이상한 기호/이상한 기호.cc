#include <iostream>

using namespace std;

int at(int a, int b)
{
	return (a + b) * (a - b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << at(a, b);
}