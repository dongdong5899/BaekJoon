#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	int nextNumber = 0;
	for (int i = 0; i < 3; i++)
	{
		if ((int)arr[i][0] < 59)
		{
			nextNumber = stoi(arr[i]) + 3 - i;
			break;
		}
	}

	bool FizzBuzz = false;
	if (nextNumber % 3 == 0)
	{
		cout << "Fizz";
		FizzBuzz = true;
	}
	if (nextNumber % 5 == 0)
	{
		cout << "Buzz";
		FizzBuzz = true;
	}
	if (FizzBuzz == false)
	{
		cout << nextNumber;
	}
}