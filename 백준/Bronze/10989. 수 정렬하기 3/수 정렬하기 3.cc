#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001]{ 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, max = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		++arr[num];
		if (max < num) max = num;
	}

	for (int i = 0; i <= max; ++i)
	{
		if (arr[i] == 0) continue;

		for (int c = 0; c < arr[i]; ++c)
		{
			cout << i << "\n";
		}
	}
}