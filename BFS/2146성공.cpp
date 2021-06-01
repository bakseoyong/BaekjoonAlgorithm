#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int> > islandPos;
int islandNum = 1;
int answer = 999999;
bool visited[100][100];


//섬을 구별
void DFS(int y, int x){
    map[y][x] = islandNum;

    for(int k = 0; k < 4; k++){
        if(y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < N && map[y + dy[k]][x + dx[k]] != 0 && !visited[y + dy[k]][x + dx[k]]){ 
            visited[y + dy[k]][x + dx[k]] = true;
            DFS(y + dy[k], x + dx[k]);
        }
    }
}

//섬마다 다른 섬까지 걸리는 거리 측정.
int BFS2(int curIslandNum){
    int result = 0;

    queue<pair<int, int> > q;

    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            if(map[i][j] == curIslandNum){
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){
        int islandCnt = q.size();

        for(int i = 0; i < islandCnt; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                //영역 안
                if(y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < N){
                    if(!map[y + dy[k]][x + dx[k]] && !visited[y + dy[k]][x + dx[k]]){ //바다라면
                        q.push(make_pair(y + dy[k], x + dx[k]));
                        visited[y + dy[k]][x + dx[k]] = true;
                    }//영역 안이며, 다른 섬일 경우
                    else if(map[y + dy[k]][x + dx[k]] && map[y + dy[k]][x + dx[k]] != curIslandNum){
                        return result;
                    }
                }
                
            }
        }

        result++;
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && map[i][j]){
                DFS(i, j);
                islandNum++;
            }
        }
    }

    for(int i = 2; i < islandNum; i++){
        memset(visited, false, sizeof(visited));
        answer = min(BFS2(i), answer);  
    }

    cout << answer;


}