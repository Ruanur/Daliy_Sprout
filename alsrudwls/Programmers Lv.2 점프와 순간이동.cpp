#include <iostream>

using namespace std;

int Calculation(int range)
{
    int battery_count = 0; 
    int temp = range;
    while (temp)
    {
        if (temp % 2)
        {
            battery_count++;
        }
        temp = temp / 2;
    }
    return battery_count;
}

int main()
{
    int n = 0;
    cin >> n;

    int result = Calculation(n);

    std::cout << result;
}
