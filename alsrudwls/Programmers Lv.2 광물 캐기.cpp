#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 피로도를 계산하는 함수
int calculateFatigue(const vector<string>& minerals, const vector<int>& picks, const vector<int>& sequence) {
    int fatigue[3][3] = {
        {1, 1, 1},   // diamond 곡괭이
        {5, 1, 1},   // iron 곡괭이
        {25, 5, 1}   // stone 곡괭이
    };
    int totalFatigue = 0;
    int mineralIndex = 0;

    for (int i = 0; i < sequence.size(); ++i) {
        int pick = sequence[i]; // 현재 선택한 곡괭이 종류
        int count = 0;          // 곡괭이로 캔 광물 개수

        while (count < 5 && mineralIndex < minerals.size()) {
            string mineral = minerals[mineralIndex];
            if (mineral == "diamond") totalFatigue += fatigue[pick][0];
            else if (mineral == "iron") totalFatigue += fatigue[pick][1];
            else if (mineral == "stone") totalFatigue += fatigue[pick][2];
            mineralIndex++;
            count++;
        }
    }

    return totalFatigue;
}

// 브루트포스를 통해 최소 피로도를 구하는 함수
int solution(vector<int> picks, vector<string> minerals) {
    int answer = INT_MAX;
    vector<int> sequence;

    // 곡괭이를 순열로 생성
    for (int i = 0; i < picks.size(); ++i) {
        for (int j = 0; j < picks[i]; ++j) {
            sequence.push_back(i);
        }
    }

    // 모든 순열 탐색
    sort(sequence.begin(), sequence.end());
    do 
    {
        answer = min(answer, calculateFatigue(minerals, picks, sequence));
    } 
    while (next_permutation(sequence.begin(), sequence.end()));

    return answer;
}