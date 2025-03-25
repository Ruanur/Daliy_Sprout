#include <bits/stdc++.h>

using namespace std;

int lab[8][8];
int original_lab[8][8];
int status[64];
int original_status[64];
int visited[8][8];

vector<pair<int, int>> index_dict;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt;
int max_cnt = 0;
int M, N;


void dfs(int y, int x){
    visited[y][x] = 1;
    lab[y][x] = 2;
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(lab[ny][nx] == 1 || lab[ny][nx] == 2) continue;
        if(visited[ny][nx] == 1) continue;

        dfs(ny, nx);
    }
}

void start_virus(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(lab[i][j] == 2 && visited[i][j] == 0)
                dfs(i, j);
        }
    }
}


int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> original_lab[i][j];
            original_status[M * i + j] = original_lab[i][j];
            index_dict.push_back({i, j});
        }
    }

    for(int i = 0; i < N * M; i++){
        for(int j = i + 1; j < N * M; j++){
            for(int k = j + 1; k < N * M; k++){
                if(original_status[i] == 1 || original_status[i] == 2) continue;
                if(original_status[j] == 1 || original_status[j] == 2) continue;
                if(original_status[k] == 1 || original_status[k] == 2) continue;

                memcpy(lab, original_lab, sizeof(original_lab));
                memcpy(status, original_status, sizeof(original_status));
                memset(visited, 0, sizeof(visited));
                status[i] = 1; status[j] = 1; status[k] = 1;

                lab[index_dict[i].first][index_dict[i].second] = 1;
                lab[index_dict[j].first][index_dict[j].second] = 1;
                lab[index_dict[k].first][index_dict[k].second] = 1;

                cnt = 0;
                start_virus();
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < M; j++){
                        if(lab[i][j] == 0)
                            cnt++;
                    }
                }
                if(cnt > max_cnt)
                    max_cnt = cnt; 
            }
        }
    }

    cout << max_cnt << endl;

    return 0;
}

// g++ -std=c++14 -Wall BOJ_14502_new.cpp -o BOJ_14502_new.out