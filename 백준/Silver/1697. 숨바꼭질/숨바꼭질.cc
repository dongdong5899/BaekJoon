#include <iostream>
#include <queue>

using namespace std;

int numArr[200001]{ 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int startPos, targetPos, count = 0;
    cin >> startPos >> targetPos;

    if (targetPos < startPos)
    {
        cout << startPos - targetPos;
        return 0;
    }

    queue<int> que;
    que.push(startPos);

    while (true)
    {
        queue<int> nextQue;
        bool flag = false;
        while (que.empty() == false)
        {
            int num = que.front();
            que.pop();

            if (num < 0 || num > targetPos * 2)
                continue;
            if (numArr[num] == 1)
                continue;

            if (num != targetPos)
            {
                nextQue.push(num + 1);
                nextQue.push(num - 1);
                nextQue.push(num * 2);
                numArr[num] = 1;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag) break;
        que = nextQue;
        ++count;
    }

    cout << count;

    return 0;
}