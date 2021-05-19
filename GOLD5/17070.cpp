#include <iostream>
using namespace std;

int N;
int map[17][17];
int cnt = 0;

void DFS(int x, int y, int pipeDir){
    if(x == N && y == N) {
        cnt++;
        return;
    } else if(x > N || y > N){
        return;
    }

    if(pipeDir == 1){
        if(map[y][x+1] != 1)
            DFS(x+1, y, pipeDir);
        if(map[y][x+1] == 0 && map[y+1][x+1] == 0 && map[y+1][x] == 0)
            DFS(x+1, y+1, pipeDir + 2);
    }else if(pipeDir == 2){
        if(map[y+1][x] != 1)
            DFS(x, y+1, pipeDir);
        if(map[y][x+1] == 0 && map[y+1][x+1] == 0 && map[y+1][x] == 0)
            DFS(x+1, y+1, pipeDir + 1);
    }else if(pipeDir == 3){
        if(map[y][x+1] != 1)
            DFS(x+1, y, pipeDir - 2);
        if(map[y+1][x] != 1)
            DFS(x, y+1, pipeDir - 1);
        if(map[y][x+1] == 0 && map[y+1][x+1] == 0 && map[y+1][x] == 0)
            DFS(x+1, y+1, pipeDir);
    }
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }

    DFS(2, 1, 1);

    cout << cnt;
}