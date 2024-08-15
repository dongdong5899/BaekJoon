#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool MyGreater(pair<int, int> time1, pair<int, int> time2)
{
    return time1.second < time2.second || (time1.second == time2.second && time1.first < time2.first);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> numMap;
    int n, count = 0, time = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        numMap.push_back({ a, b });
    }

    sort(numMap.begin(), numMap.end(), MyGreater);

    for (pair<int, int> timeData : numMap)
    {
        if (timeData.first < time || timeData.second < time) continue;

        time = timeData.second;
        ++count;
    }

    cout << count;

    return 0;
}