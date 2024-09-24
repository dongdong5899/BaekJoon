#include <string>
#include <vector>

using namespace std;

int DFS(int idx, vector<int> numbers, int num, int target)
{
    if (idx == numbers.size())
    {
        return num == target ? 1 : 0;
    }
    return DFS(idx + 1, numbers, num + numbers[idx], target) + DFS(idx + 1, numbers, num - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    int answer = DFS(0, numbers, 0, target);
    
    return answer;
}