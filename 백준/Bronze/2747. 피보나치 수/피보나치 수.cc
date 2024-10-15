#include <iostream>

using namespace std;

int main()
{
    int arr[48] = {0, 1};
    int num;
    cin >> num;
    
    for (int i = 0; i < num; ++i)
    {
        arr[i + 2] = arr[i] + arr[i + 1];
    }
    cout << arr[num];
}