#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int Work(vector<int>& schedules, vector<vector<int>>& timelogs, queue<int> day) {
    int result = 0;

    for (int i = 0; i < schedules.size(); i++) {
        queue<int> days = day;
        bool isEligible = true;
        for (int j = 0; j < 7; j++) {
            int current_day = days.front();
            days.pop();

            if (current_day == 6 || current_day == 7) {
                continue;
            }

            if (timelogs[i][j] > schedules[i] + 10) {
                isEligible = false;
                break;
            }
        }

        if (isEligible) {
            result++;
        }
    }
    return result;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    queue<int> day;

    for (int i = 0; i < 7; i++) {
        day.push((startday + i - 1) % 7 + 1);
    }

    answer = Work(schedules, timelogs, day);

    return answer;
}