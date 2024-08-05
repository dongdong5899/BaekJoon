#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[1002]{ 0, 1, };
	for (int i = 2; i <= 1001; ++i)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	int num;
	cin >> num;

	cout << arr[num + 1];
}