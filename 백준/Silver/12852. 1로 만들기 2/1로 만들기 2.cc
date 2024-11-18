#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num, *dp;
    cin >> num;

    dp = new int[num + 1] {0};

    for (int i = 2; i <= num; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[num] << "\n";

    int path = num;
    while (path > 0)
    {
        cout << path << " ";
        int nextPath = path - 1;
        if (path % 3 == 0 && dp[nextPath] > dp[path / 3])
            nextPath = path / 3;
        if (path % 2 == 0 && dp[nextPath] > dp[path / 2])
            nextPath = path / 2;
        path = nextPath;
    }
}