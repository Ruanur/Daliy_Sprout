#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int arr[100][100];
int visited[100][100];
int left_y, left_x, right_y, right_x;
int cnt = 0;
vector<int> gnd_list;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int, int);

int main(){
    cin >> M >> N >> K;

    memset(arr, 0, sizeof(int) * 10000);
    memset(visited, 0, sizeof(int) * 10000);

    for(int i = 0; i < K; i++){
        cin >> left_x >> left_y >> right_x >> right_y;
        for(int j = left_x; j < right_x; j++){
            for(int k = left_y; k < right_y; k++){
                arr[k][j] = 1;
            }
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 1) continue;
            if(arr[i][j] == 1) continue;
            int gnd = 0;
            gnd = dfs(i, j);
            cnt++;
            gnd_list.push_back(gnd);
        }
    }

    sort(gnd_list.begin(), gnd_list.end());

    cout << cnt << '\n';
    for(int i : gnd_list){
        cout << i << ' ';
    }

    return 0;
}


int dfs(int y, int x){
    visited[y][x] = 1;
    int gnd = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if(visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 1) continue;

        gnd += dfs(ny, nx);
    }

    return gnd;
}

// g++ -std=c++14 -Wall BOJ_2583_new.cpp -o BOJ_2583_new.out