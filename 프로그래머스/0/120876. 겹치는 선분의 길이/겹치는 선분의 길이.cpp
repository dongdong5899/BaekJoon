#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    set<int> mySet;
    set<int> sideSet;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = lines[i][0]; j < lines[i][1]; ++j)
        {
            if (mySet.find(j) != mySet.end())
            {
                if (sideSet.find(j) == sideSet.end())
                    sideSet.insert(j);
            }
            else
            {
                mySet.insert(j);
            }
        }
    }
    answer = sideSet.size();

    return answer;
}