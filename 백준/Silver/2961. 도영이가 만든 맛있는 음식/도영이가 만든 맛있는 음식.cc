#include <iostream>

using namespace std;

int n;
pair<int, int> numPair[10];

int diff(int idx, pair<int, int> sums)
{
    pair<int, int> newSums = sums;
    newSums.first /= numPair[idx].first;
    newSums.second -= numPair[idx].second;

    int sumDif = abs(sums.first - sums.second);
    int newSumDif = abs(newSums.first - newSums.second);

    if (newSums.second == 0) return sumDif;
    if (idx >= n - 1)
    {
        return min(newSumDif, sumDif);
    }
    return min(diff(idx + 1, newSums), diff(idx + 1, sums));
}

int main() {

    pair<int, int> sumPair = { 1, 0 };
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> numPair[i].first >> numPair[i].second;
        sumPair.first *= numPair[i].first;
        sumPair.second += numPair[i].second;
    }

    cout << diff(0, sumPair);

    return 0;
}