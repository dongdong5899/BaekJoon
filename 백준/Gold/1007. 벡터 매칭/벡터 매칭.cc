#include <iostream>
#include <math.h>

using namespace std;

class vector
{
private :
	bool isReversed = false;
public:
	int x;
	int y;
	vector(int _x, int _y) : x{ _x }, y{ _y } {};
	vector() : x{ 0 }, y{ 0 } {};
	double disPow()
	{
		return pow(x, 2) + pow(y, 2);
	}
	void reverse()
	{
		if (isReversed) return;
		x = -x;
		y = -y;
		isReversed = true;
	}
	void original()
	{
		if (isReversed == false) return;
		x = -x;
		y = -y;
		isReversed = false;
	}

	void operator+=(const vector& vec)
	{
		x += vec.x;
		y += vec.y;
	}
};


int pointCount;
vector* pointPos;

vector sumVector()
{
	vector sumVec;
	for (int i = 0; i < pointCount; ++i)
	{
		sumVec += pointPos[i];
	}

	return sumVec;
}
vector findMinVector(int startIndex, int level, vector minSum, double minDis)
{
	if (level == 0) return sumVector();

	pointPos[startIndex].reverse();
	for (int i = startIndex + 1; i <= pointCount - level; ++i)
	{
		pointPos[i].original();
	}

	for (int i = startIndex; i <= pointCount - level; ++i)
	{
		vector sumT = findMinVector(i + 1, level - 1, minSum, minDis);
		double value = sumT.disPow();
		if (value < minDis)
		{
			minDis = value;
			minSum = sumT;
		}

		if (i == pointCount - level) break;
		pointPos[i].original();
		pointPos[i + 1].reverse();
	}

	return minSum;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	for (int k = 0; k < count; k++)
	{
		vector minSum;
		cin >> pointCount;
		pointPos = new vector[pointCount];
		for (int i = 0; i < pointCount; ++i)
		{
			cin >> pointPos[i].x;
			cin >> pointPos[i].y;

			if (i < pointCount / 2)pointPos[i].reverse();
			minSum += pointPos[i];
		}

		minSum = findMinVector(1, pointCount / 2 - 1, minSum, minSum.disPow());

		cout << fixed;
		cout.precision(12);
		cout << sqrt(minSum.disPow()) << endl;
	}
}