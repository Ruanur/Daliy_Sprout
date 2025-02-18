#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; // 집의 수
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(3));

    // 비용 입력
    for (int i = 0; i < N; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // DP 테이블 초기화
    vector<vector<int>> dp(N, vector<int>(3, 0));

    // 첫 번째 집 비용 초기화
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    // DP 테이블 채우기
    for (int i = 1; i < N; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    // 최소 비용 계산
    int min_cost = min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });

    cout << min_cost << endl;

    return 0;
}
