#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, arr[12]{ 1, };
	cin >> N;

	for (int i = 1; i < 12; ++i)
	{
		arr[i] = arr[i - 1];
		if (i > 1) arr[i] += arr[i - 2];
		if (i > 2) arr[i] += arr[i - 3];
	}

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		cout << arr[num] << "\n";
	}
}