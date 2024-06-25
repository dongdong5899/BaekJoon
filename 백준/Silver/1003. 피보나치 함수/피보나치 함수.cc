#include <iostream>
#include <math.h>

using namespace std;

int F(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
			cout << 1 << " " << 0 << endl;
		else if (num == 1)
			cout << 0 << " " << 1 << endl;
		else
			cout << F(num - 1) << " " << F(num) << endl;
	}
}

int memory[41];
int F(int n)
{
	if (memory[n] != 0)
		return memory[n];
	if (n == 0 || n == 1)
		return n;
	memory[n] = F(n - 1) + F(n - 2);
	return memory[n];
}