#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000]{ 0, };

class pos
{
public :
    int x = 0;
    int y = 0;
    pos operator+ (const pos& p)
    {
        pos res;
        res.x = x + p.x;
        res.y = y + p.y;
        return res;
    }
};
pos dir[4]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pos> posQue;
    pos startPos;
    int x, y, count = -1, tCount = 0;
    cin >> x >> y;

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            int num;
            cin >> num;
            arr[i][j] = num == -1 ? 0 : -1;
            if (num == 1)
                posQue.push({ j, i });
        }
    }

    while (posQue.empty() == false)
    {
        queue<pos> newPosQue;
        ++count;
        while (posQue.empty() == false)
        {
            pos position = posQue.front();
            posQue.pop();
            if (arr[position.y][position.x] != -1) continue;
            arr[position.y][position.x] = 1;
            for (size_t i = 0; i < 4; i++)
            {
                pos pos = position + dir[i];

                if (pos.x < 0 || pos.y < 0 || pos.x >= x || pos.y >= y) continue;

                newPosQue.push(pos);
            }
        }
        posQue = newPosQue;
    }


    bool flag = false;
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            if (arr[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << count - 1;

    return 0;
}