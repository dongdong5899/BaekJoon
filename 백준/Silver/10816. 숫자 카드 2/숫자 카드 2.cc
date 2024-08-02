#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, *arr1, *arr2;
	unordered_map<int, int> numMap;
	
	cin >> N;
	arr1 = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> arr1[i];
		if (numMap.find(arr1[i]) == numMap.end())
		{
			numMap.insert({ arr1[i], 0 });
		}
		++numMap[arr1[i]];
	}
	cin >> M;
	arr2 = new int[M];
	for (int i = 0; i < M; ++i)
	{
		cin >> arr2[i];
		if (numMap.find(arr2[i]) == numMap.end())
			cout << 0;
		else
			cout << numMap[arr2[i]];
		cout << " ";
	}
}