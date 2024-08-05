#include <iostream>

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}

	for (int i = 0; i < M; ++i)
	{
		int start, end, sum = 0;
		cin >> start >> end;

		cout << arr[end] - arr[start - 1] << "\n";
	}
}