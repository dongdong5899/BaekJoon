#include <iostream>
#include <math.h>

using namespace std;

class vector 
{
public :
	int x;
	int y;
	bool isReversed = false;
	vector(int _x, int _y) : x{ _x }, y{ _y } {};
	vector() : x{ 0 }, y{ 0 } {};
	double disSqrt()
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

	vector operator+(const vector &vec)
	{
		vector res;

		res.x = x + vec.x;
		res.y = y + vec.y;

		return res;
	}
	vector operator*(const int &value)
	{
		vector res;

		res.x = x * value;
		res.y = y * value;

		return res;
	}
	void operator+=(const vector &vec)
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
vector findMinVector(int startIndex, int level, vector startSum, double startdis)
{
	if (level == 0) return sumVector();

	double minDis = startdis;
	vector minSum = startSum;

	pointPos[startIndex].reverse();
	for (int i = startIndex + 1; i <= pointCount - level; ++i)
	{
		pointPos[i].original();
	}

	for (int i = startIndex; i < pointCount - level; ++i)
	{
		vector sumT = findMinVector(i + 1, level - 1, minSum, minDis);
		double value = sumT.disSqrt();
		if (value < minDis)
		{
			minDis = value;
			minSum = sumT;
		}

		pointPos[i].original();
		pointPos[i + 1].reverse();
	}
	vector sumT = findMinVector(pointCount - level + 1, level - 1, minSum, minDis);
	double value = sumT.disSqrt();
	if (value < minDis)
	{
		minDis = value;
		minSum = sumT;
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
		vector sum;
		cin >> pointCount;
		pointPos = new vector[pointCount];
		for (int i = 0; i < pointCount; ++i)
		{
			cin >> pointPos[i].x;
			cin >> pointPos[i].y;

			if (i < pointCount / 2)
				pointPos[i].reverse();

			sum += pointPos[i];
		}

		vector minSum = findMinVector(1, pointCount / 2 - 1, sum, sum.disSqrt());

		cout << fixed;
		cout.precision(12);
		cout << sqrt(minSum.disSqrt()) << endl;
	}
}

