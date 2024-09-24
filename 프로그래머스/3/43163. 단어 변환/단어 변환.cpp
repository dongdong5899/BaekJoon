#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool IsLinked(string first, string second)
{
    int sameCnt = 0;
    int length = first.length();
    for (int i = 0; i < length; i++)
    {
        if (first[i] == second[i])
        {
            sameCnt++;
        }
    }
    return sameCnt == length - 1;
}

int BFS(string ward, string target, vector<string> words)
{
	set<string> strSet;
	queue<string> que;
	que.push(ward);
	int cnt = 0;
    bool flag = false;
	while (que.empty() == false)
	{
		string str = que.front();
		que.pop();
		for (int i = 0; i < words.size(); i++)
		{
			if (IsLinked(str, words[i]) && strSet.find(words[i]) == strSet.end())
			{
				strSet.insert(words[i]);
				que.push(words[i]);
				if (words[i] == target)
				{
					que = queue<string>();
                    flag = true;
					break;
				}
			}
		}
		cnt++;
	}
	return flag ? cnt : 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = BFS(begin, target, words);
    return answer;
}