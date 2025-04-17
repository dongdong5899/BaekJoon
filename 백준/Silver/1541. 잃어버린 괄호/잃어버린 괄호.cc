#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string nums;
	cin >> nums;

	bool onMinusMode = false;
	int totalNum = 0;
	string numStr = "";
	for (int i = 0; i < nums.length(); ++i)
	{
		if (nums[i] == '-')
		{
			if (onMinusMode)
				totalNum -= stoi(numStr);
			else
				totalNum += stoi(numStr);
			numStr = "";
			onMinusMode = true;
		}
		else if (nums[i] == '+')
		{
			if (onMinusMode)
				totalNum -= stoi(numStr);
			else
				totalNum += stoi(numStr);
			numStr = "";
		}
		else
		{
			numStr += nums[i];
		}
	}
	if (onMinusMode)
		totalNum -= stoi(numStr);
	else
		totalNum += stoi(numStr);

	cout << totalNum;
}