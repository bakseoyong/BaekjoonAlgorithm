#include <iostream>
using namespace std;

int M, N;
int map[501][501];
bool visited[501][501];
int dp[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(int y, int x){
    for(int k = 0; k < 4;k++){
        int my = y + dy[k];
        int mx = x + dx[k];

        if(my < 0 || my >= M || mx < 0 || mx >= N) continue;
        if(visited[my][mx] == false){
            visited[my][mx] = true;
            dp[my][mx] = 1;
        }else if(map[my][mx] > map[y][x] && visited[my][mx] == true){
            dp[my][mx] += dp[y][x];
        }

        DFS(my, mx);

    }
}

int main(){
    cin >> M >> N;

    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    DFS(M-1, N-1);
    cout << dp[0][0];
}