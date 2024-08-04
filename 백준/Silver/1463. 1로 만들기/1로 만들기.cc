#include <iostream>

using namespace std;

int arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	for (int i = 2; i <= num; ++i)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
	}

	cout << arr[num];
}