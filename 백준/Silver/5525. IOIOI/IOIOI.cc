#include <iostream>

using namespace std;

int main()
{
	string str;
	int N;
	cin >> N;

	int M;
	cin >> M;

	cin >> str;

	int count = 0;
	for (size_t i = 0; i < M - 2 * N; i++)
	{
		bool flag = true;
		for (size_t j = 0; j < 2 * N + 1; j++)
		{
			if (str[i + j] != (j % 2 == 0 ? 'I' : 'O'))
			{
				flag = false;
				break;
			}
		}
		if (flag) count++;
	}

	cout << count;
}