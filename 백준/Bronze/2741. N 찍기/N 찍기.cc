#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int num;
	std::cin >> num;

	for (int i = 1; i <= num; ++i)
	{
		std::cout << i << "\n";
	}
}