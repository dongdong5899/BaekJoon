#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string> map;

    int x, y;
    cin >> x >> y;

    for (int i = 0; i < x; ++i)
    {
        string site, psw;
        cin >> site >> psw;
        map.insert({ site, psw });
    }

    for (int i = 0; i < y; ++i)
    {
        string str;
        cin >> str;
        cout << map[str] << "\n";
    }

    return 0;
}