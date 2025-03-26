#include <bits/stdc++.h>

using namespace std;

int T, M, N, K;
int Y, X;
int arr[50][50];
int visited[50][50];
vector<int> answer;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int, int);

int main(){
    
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        int answer_count = 0;
        memset(arr, 0, sizeof(int) * 2500);
        memset(visited, 0, sizeof(int) * 2500);
        cin >> N >> M >> K;
        for(int i = 0; i < K; i++){
            cin >> Y >> X;
            arr[Y][X] = 1;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] == 1 && visited[i][j] == 0){
                    answer_count++;
                    dfs(i, j);
                }
            }
        }

        answer.push_back(answer_count);
    }
    
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }

    return 0;
}

void dfs(int y, int x){
    visited[y][x] = 1;
    int ny, nx;

    for(int i = 0; i < 4; i++){
        ny = dy[i] + y;
        nx = dx[i] + x;
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(arr[ny][nx] == 0) continue;
        if(visited[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

// g++ -std=c++14 -Wall BOJ_1012_new.cpp -o BOJ_1012_new.out