#include <iostream>

int main()
{
    int num, sum = 0;
    std::cin >> num;
    
    for (int i = 1; i <= num; ++i)
    {
        sum += i;
    }
    
    std::cout << sum;
}