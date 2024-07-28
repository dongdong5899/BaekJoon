#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{
		bool res = true;
		string str;
		int length;
		cin >> str;
		length = str.length();

		int idx = 0;
		while (idx < length)
		{
			if (str[idx] == '1')
			{
				if (idx + 2 >= length || str.substr(idx, 3) != "100")
				{
					res = false;
					break;
				}
				idx += 3;
				bool readyChange = false;
				int oneCount = 0;
				while (idx < length)
				{
					if (str[idx] == '0')
					{
						if (readyChange == false)
							++idx;
						else
							break;
					}
					else
					{
						readyChange = true;
						++oneCount;
						++idx;
					}
				}
				if (idx >= length)
				{
					if (readyChange == false) res = false;
					break;
				}
				if (oneCount == 0)
				{
					res = false;
					break;
				}
				if (oneCount > 1 && (idx + 1 >= length || str.substr(idx, 2) == "00")) --idx;
			}
			else
			{
				if (idx + 1 >= length || str.substr(idx, 2) != "01")
				{
					res = false;
					break;
				}
				idx += 2;
			}
		}


		cout << (res ? "YES" : "NO") << endl;
	}
}