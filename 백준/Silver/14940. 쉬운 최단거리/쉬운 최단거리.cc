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
    int x, y, count = 0;
    cin >> x >> y;

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            int num;
            cin >> num;
            arr[j][i] = num == 1 ? -1 : 0;
            if (num == 2)
                posQue.push({ i, j });
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
            for (size_t i = 0; i < 4; i++)
            {
                pos pos = position + dir[i];

                if (pos.x < 0 || pos.y < 0 || pos.x >= x || pos.y >= y) continue;
                if (arr[pos.y][pos.x] != -1) continue;

                newPosQue.push(pos);
                arr[pos.y][pos.x] = count;
            }
        }
        posQue = newPosQue;
    }


    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}