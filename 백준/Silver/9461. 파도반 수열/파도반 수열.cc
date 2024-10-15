#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    long long arr[103] = { 0, 1, 0 };
    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; ++i)
    {
        int num;
        cin >> num;

        for (int i = 3; i < num + 3; ++i)
        {
            if (arr[num + 2] != 0) break;
            arr[i] = arr[i - 2] + arr[i - 3];
        }
        cout << arr[num + 2] << "\n";
    }
}