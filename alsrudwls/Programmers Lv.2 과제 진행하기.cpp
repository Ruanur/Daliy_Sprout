#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// 문자열 시간을 분으로 변환
int timeToMinutes(const string& time) {
    int hours, minutes;
    char colon;
    stringstream ss(time);
    ss >> hours >> colon >> minutes;
    return hours * 60 + minutes;
}

int main() {
    vector<vector<string>> plans = {
        {"korean", "11:40", "30"},
        {"english", "12:10", "20"},
        {"math", "12:30", "40"}
    };

    // 시작 시간 기준으로 정렬
    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return timeToMinutes(a[1]) < timeToMinutes(b[1]);
        });

    // 정렬 결과 출력
    for (const auto& plan : plans) {
        cout << "Subject: " << plan[0]
            << ", Start Time: " << plan[1]
            << ", Duration: " << plan[2] << endl;
    }

    return 0;
}