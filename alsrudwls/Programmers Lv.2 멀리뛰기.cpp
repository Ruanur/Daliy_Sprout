
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[2001];

    dp[1] = 1;
    dp[2] = 2;

    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    else if (n == 2)
    {
        cout << "2";
        return 0;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    long long answer = dp[n] % 1234567;
    std::cout << answer;
}