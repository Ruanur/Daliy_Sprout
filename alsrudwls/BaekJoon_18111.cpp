#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int ground[502][502]; // 땅의 높이를 저장하는 배열
int N, M, B; // N: 세로 길이, M: 가로 길이, B: 인벤토리의 블록 수
int best_height = 0; // 최적의 높이
int min_time = INT_MAX; // 최소 시간

// 주어진 높이에서 블록을 추가 및 제거하여 최적의 높이를 찾는 함수
void blockCheck()
{
    for (int h = 0; h <= 256; h++) { // 0부터 256 높이까지 반복
        int remove_blocks = 0; // 제거할 블록 수
        int add_blocks = 0; // 추가할 블록 수
        for (int i = 0; i < N; i++) { // 세로 길이만큼 반복
            for (int j = 0; j < M; j++) { // 가로 길이만큼 반복
                if (ground[i][j] > h) { // 현재 높이가 목표 높이보다 크면
                    remove_blocks += ground[i][j] - h; // 제거할 블록 수 계산
                }
                else if (ground[i][j] < h) { // 현재 높이가 목표 높이보다 작으면
                    add_blocks += h - ground[i][j]; // 추가할 블록 수 계산
                }
            }
        }
        if (remove_blocks + B >= add_blocks) { // 제거할 블록과 인벤토리의 블록이 추가할 블록보다 많거나 같을 때
            int time = remove_blocks * 2 + add_blocks; // 소요 시간 계산
            if (time <= min_time) { // 최소 시간 업데이트
                min_time = time;
                best_height = h; // 최적의 높이 업데이트
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); // 입출력 속도 향상
    cin.tie(0); cout.tie(0); // 입출력 속도 향상

    cin >> N >> M >> B; // 세로 길이, 가로 길이, 인벤토리 블록 수 입력
    for (int i = 0; i < N; i++) { // 세로 길이만큼 반복
        for (int j = 0; j < M; j++) { // 가로 길이만큼 반복
            cin >> ground[i][j]; // 땅의 높이 입력
        }
    }
    blockCheck(); // 최적의 높이와 시간을 찾는 함수 호출
    cout << min_time << " " << best_height << endl; // 결과 출력
    return 0;
}
