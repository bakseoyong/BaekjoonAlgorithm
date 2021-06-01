#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int> > islandPos;
int islandNum = 2;
int answer = 999999;
bool visited[100][100];


//섬을 구별
void BFS(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                islandPos.push(make_pair(i, j));

                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    map[y][x] = islandNum;

                    for(int k = 0; k < 4; k++){
                        if(y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < N && map[y + dy[k]][x + dx[k]] == 1){
                            map[y + dy[k]][x + dx[k]] = islandNum;
                            q.push(make_pair(y + dy[k], x + dx[k]));
                            islandPos.push(make_pair(i, j));
                        }
                    }
                }

                islandNum++;
            }
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
            visited[y][x] = true;

            for(int k = 0; k < 4; k++){
                //영역 밖이거나 같은 섬이라면 continue
                if(y + dy[k] < 0 || y + dy[k] >= N || x + dx[k] < 0 || x + dx[k] >= N || map[y + dy[k]][x + dx[k]] == curIslandNum) continue;
                //영역 안이지만 바다인 경우
                else if(!map[y + dy[k]][x + dx[k]]){
                    q.push(make_pair(y + dy[k], x + dx[k]));
                    visited[y + dy[k]][x + dx[k]] = true;
                }//영역 안이며, 다른 섬일 경우
                else if(map[y + dy[k]][x + dx[k]] != curIslandNum){
                    return result;
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

    BFS();

    for(int i = 2; i < islandNum; i++){
        memset(visited, false, sizeof(visited));
        answer = min(BFS2(i), answer);  
    }

    cout << answer;


}