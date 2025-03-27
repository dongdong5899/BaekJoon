#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[1002]{ 0, 1, };

	int num;
	cin >> num;
	for (int i = 2; i <= num + 1; ++i)
	{
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	}

	cout << arr[num + 1];
}