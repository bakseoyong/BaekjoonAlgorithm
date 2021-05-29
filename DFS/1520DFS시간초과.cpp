#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int M, N;
int map[501][501];
int dp[501][501] = { 0, };
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
queue<pair<int, int> > q;
int answer = 0;
int visited[501][501] = {0, };


void a(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N;j++){
            for(int k = 0; k < 4; k++){
                if(i+dy[k] < 0 || i+dy[k] >= M) continue;
                if(j+dx[k] < 0 || j+dx[k] >= N) continue;
                if(map[i][j] < map[i+dy[k]][j+dx[k]])
                    dp[i][j]++;
            }
        }
    }
}

void b(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j <N; j++){
            if(i == 0 && j == 0) continue;
            if(dp[i][j] == 0 )
                q.push(make_pair(i, j));
        }   
    }
}

void c(){
    int tempVisited[501][501] = {0, };
    tempVisited[0][0] = 1;

    while(!q.empty()){
        int y, x;
        y = q.front().first;
        x = q.front().second;
        q.pop();
        tempVisited[y][x] = 1;

        for(int k = 0; k < 4; k++){
            if(y+dy[k] < 0 || y+dy[k] >= M) continue;
            if(x+dx[k] < 0 || x+dx[k] >= N) continue;

            if((map[y][x] > map[y+dy[k]][x+dx[k]]) && tempVisited[y+dy[k]][x+dx[k]] == 0)
                dp[y+dy[k]][x+dx[k]]--;
            if(dp[y+dy[k]][x+dx[k]] == 0 && tempVisited[y+dy[k]][x+dx[k]] == 0){
                q.push(make_pair(y+dy[k], x+dx[k]));
            }
        }
    }
}

void DFS(int y, int x){
    if(y == M-1 && x == N-1){
        answer++;
        return;
    }

    for(int k = 0; k< 4; k++){
        if(y+dy[k] < 0 || y+dy[k] >= M) continue;
        if(x+dx[k] < 0 || x+dx[k] >= N) continue;

        if(dp[y+dy[k]][x+dx[k]] != 0 && visited[y+dy[k]][x+dx[k]] == 0){
            visited[y+dy[k]][x+dx[k]] = 1;
            DFS(y+dy[k], x+dx[k]);
            visited[y+dy[k]][x+dx[k]] = 0;
        }
    }


}

int main(){
    
    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    a();
    b();
    c();
    DFS(0, 0);

    cout << answer;

}