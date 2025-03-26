#include <bits/stdc++.h>

using namespace std;

int N;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int arr[100][100];
int visited[100][100];
int height = 0;
int area_cnt = 0;
int max_cnt = 1;

void dfs(int, int);

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    // 초기화 단계


    for(int i = 1; i < 101; i++){
        memset(visited, 0, sizeof(int) * 10000);
        area_cnt = 0;
        height = i;

        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(visited[j][k] == 1) continue;
                if(arr[j][k] <= height) continue;

                area_cnt++;
                dfs(j, k);
            }
        }

        if(area_cnt > max_cnt)
            max_cnt = area_cnt;
    }

    cout << max_cnt << '\n';

    return 0;
}


void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(visited[ny][nx] == 1) continue;
        if(arr[ny][nx] <= height) continue;

        dfs(ny, nx);
    }
}


// g++ -std=c++14 -Wall BOJ_2468_new.cpp -o BOJ_2468_new.out