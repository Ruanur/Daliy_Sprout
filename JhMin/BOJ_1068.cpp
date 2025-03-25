#include <bits/stdc++.h>

using namespace std;

vector<int> adj[50];
int visited[50];
int root = 0;


int dfs(int here){
    int leaf_count = 0;

    for(int i: adj[here]){
        if(visited[i] == 1) continue;
        leaf_count += dfs(i);
    }

    if(leaf_count == 0) return 1;

    return leaf_count;
}

int solve(int remove){
    if(remove == root) return 0;

    visited[remove] = 1;

    int cnt;
    cnt = dfs(root);
    return cnt;
}


int main(void){
    int N = 0;
    int value = 0;
    int remove, result;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> value;

        if(value == -1){
            root = i;
            continue;
        }

        adj[value].push_back(i);
    }

    cin >> remove;
    result = solve(remove);
    cout << result << "\n";

    return 0;
}


// g++ -std=c++14 -Wall BOJ_1068_new.cpp -o BOJ_1068_new.out