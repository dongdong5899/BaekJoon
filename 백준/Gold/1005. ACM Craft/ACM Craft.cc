#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


int makeTime(int* buildTime, unordered_map<int, int>* buildTimeMap, unordered_map<int, vector<int>> buildLink, int buildingIndex)
{
	if (buildLink.find(buildingIndex) == buildLink.end())
	{
		return buildTime[buildingIndex];
	}

	int maxTime = 0;
	for (auto prevBuild : buildLink[buildingIndex])
	{
		int time = 0;
		if (buildTimeMap->find(prevBuild) != buildTimeMap->end())
			time = buildTimeMap->at(prevBuild);
		else
		{
			time = makeTime(buildTime, buildTimeMap, buildLink, prevBuild);
			buildTimeMap->insert({ prevBuild, time });
		}

		if (time > maxTime)
		{
			maxTime = time;
		}
	}

	return maxTime + buildTime[buildingIndex];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int N, K, lastBuild;
		cin >> N;
		cin >> K;
		int* buildTime;
		buildTime = new int[N + 1];
		unordered_map<int, vector<int>> buildLink;
		unordered_map<int, int> buildTimeMap;

		//건설시간 받기
		for (int j = 1; j <= N; ++j)
		{
			cin >> buildTime[j];
		}
		//건설설계 받기
		for (int j = 0; j < K; ++j)
		{
			int in, out;
			cin >> in;
			cin >> out;
			if (buildLink.find(out) == buildLink.end())
				buildLink.insert({ out, vector<int>()});
			buildLink[out].push_back(in);
		}
		//마지막 건물
		cin >> lastBuild;

		cout << makeTime(buildTime, &buildTimeMap, buildLink, lastBuild) << endl;
	}
}