#include <string>
#include <vector>

using namespace std;
vector<int> picked;
int CountAnswer = 0;
int RangeNumber = 0;
vector<vector<int>> Question;
vector<int> Answer;

bool IsValid(const vector<vector<int>>& secret, const vector<int>& answer, const vector<int>& picked)
{
    for (int i = 0; i < secret.size(); i++)
    {
        int matchCount = 0;

        for (int a : picked)
        {
            for (int b : secret[i])
            {
                if (a == b)
                {
                    matchCount++;
                }
            }
        }
        if (matchCount != answer[i])
        {
            return false;
        }
    }
    return true;
}

void picked_dfs(int start, int depth)
{
    if (depth == 5)
    {
        if (IsValid(Question, Answer, picked))
        {
            CountAnswer++;
        }
        return;
    }
    for (int i = start; i <= RangeNumber; i++)
    {
        picked.push_back(i);
        picked_dfs(i + 1, depth + 1);
        picked.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    RangeNumber = n;
    Question = q;
    Answer = ans;

    picked_dfs(1, 0);
    return CountAnswer;
}