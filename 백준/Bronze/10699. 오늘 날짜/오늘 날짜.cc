#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	time_t t = time(NULL);
	tm time = *localtime(&t);
	cout.fill('0');
	cout.width(4);
	cout << time.tm_year + 1900 << "-";
	cout.width(2);
	cout << time.tm_mon + 1 << "-" << time.tm_mday << endl;
}