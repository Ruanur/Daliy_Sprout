#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> count;

    for (int size : tangerine)
    {
        count[size]++;
    }

    vector<int> counts;

    for (auto pair : count)
    {
        counts.push_back(pair.second);
    }

    // 큰 수 부터 정렬
    sort(counts.begin(), counts.end(), greater<int>());

    int sum = 0;
    int answer = 0;

    for (int c : counts)
    {
        sum += c;
        answer++;

        if (sum >= k)
        {
            break;
        }
    }

    return answer;
}