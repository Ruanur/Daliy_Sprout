#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = log2(n);

    while (answer > 0)
    {
        int half_match_team = n / 2;

        bool aLeft = a <= half_match_team;
        bool bLeft = b <= half_match_team;

        if (aLeft != bLeft)
        {
            return answer;
        }

        if (!aLeft && !bLeft)
        {
            a -= half_match_team;
            b -= half_match_team;
        }

        n /= 2;
        answer--;
    }

    return answer;
}