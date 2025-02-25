#include <iostream>
#include <queue>
#include <unordered_set>
#include <stdint.h>

using namespace std;

// A를 B로 변환하는 데 필요한 최소 연산 횟수를 계산하는 함수
int minOperations(int64_t A, int64_t B) {
    // A가 B와 동일한 경우 0을 반환
    if (A == B)
    {
        return 0;
    }

    // BFS를 위한 큐와 방문 집합 생성
    queue<pair<int64_t, int>> q;
    unordered_set<int64_t> visited;

    // 초기 상태를 큐에 추가하고 방문 집합에 등록
    q.push({ A, 0 });
    visited.insert(A);

    // 큐가 빌 때까지 반복
    while (!q.empty()) 
    {
        int64_t current = q.front().first; // 현재 수
        int steps = q.front().second; // 현재까지의 연산 횟수
        q.pop();

        // 연산 1: 2를 곱한다.
        int64_t next = current * 2;
        if (next == B)
        {
            return steps + 2; // 목표 값에 도달하면 최솟값에 1을 더한 값 반환
        }
        if (next < B && visited.find(next) == visited.end()) 
        {
            q.push({ next, steps + 1 }); // 큐에 추가하고 방문 집합에 등록
            visited.insert(next);
        }

        // 연산 2: 1을 가장 오른쪽에 추가한다.
        next = current * 10 + 1;
        if (next == B)
        {
            return steps + 2; // 목표 값에 도달하면 최솟값에 1을 더한 값 반환
        }
        if (next < B && visited.find(next) == visited.end()) {
            q.push({ next, steps + 1 }); // 큐에 추가하고 방문 집합에 등록
            visited.insert(next);
        }
    }

    return -1; // 변환이 불가능한 경우 -1 반환
}

int main() {
    int64_t A, B;
    // 사용자로부터 A와 B 값을 입력받음
    cin >> A >> B;

    // A를 B로 변환하는 데 필요한 최소 연산 횟수를 계산
    int result = minOperations(A, B);
    // 결과를 출력
    cout << result << endl;

    return 0;
}
