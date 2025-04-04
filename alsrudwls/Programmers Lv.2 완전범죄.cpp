#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    // dp[a][b]: A의 누적 흔적이 a, B의 누적 흔적이 b인 상태 가능 여부
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    dp[0][0] = true; // 초기 상태

    int itemCnt = info.size();

    for (int i = 0; i < itemCnt; i++) {
        // 다음 단계 DP 테이블 초기화
        vector<vector<bool>> nextDp(n, vector<bool>(m, false));

        int traceA = info[i][0];
        int traceB = info[i][1];

        // 이전 상태를 기반으로 가능한 상태 계산
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[a][b]) continue; // 현재 상태가 불가능하면 건너뛴다.

                // A 도둑이 물건을 훔치는 경우
                if (a + traceA < n) {
                    nextDp[a + traceA][b] = true;
                }

                // B 도둑이 물건을 훔치는 경우
                if (b + traceB < m) {
                    nextDp[a][b + traceB] = true;
                }
            }
        }

        // DP 갱신
        dp = nextDp;
    }

    // 가능한 최소 A의 흔적 반환
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (dp[a][b]) {
                return a;
            }
        }
    }

    // 두 도둑 모두 경찰에 붙잡히지 않는 방법이 없는 경우
    return -1;
}