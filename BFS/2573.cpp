#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int map[300][300] = { 0, };
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;
int visited[300][300] = { 0,};
int isIslandCnt;


//빙산 갈라짐 확인
void DFS(int y, int x){

    if(visited[y][x] == true)
        return;
    else{
        visited[y][x] = true;
        for(int k = 0; k < 4; k++){
            int tempY = y + dy[k];
            int tempX = x + dx[k];
            if(tempY >= 0 && tempY < N && tempX >= 0 && tempX < M && map[tempY][tempX] != 11 && map[tempY][tempX] > 0){
                DFS(tempY, tempX);
            }
        }
    }
    
}

int BFS(){
    int answer = 0;
    int thisYearIslandNum = 0;
    int copyMap[300][300];
    int islandScale;

    while(1){
        thisYearIslandNum = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0;  j < M; j++){
                if(visited[i][j] == false && map[i][j]){
                    DFS(i, j);
                    thisYearIslandNum++;
                }
            }
        }
        if(thisYearIslandNum == 0) return 0;
        else if(thisYearIslandNum >= 2) return answer;
        memset(visited, false, sizeof(visited));
        memcpy(copyMap, map, sizeof(map));

        islandScale = q.size();
        for(int i = 0; i < islandScale; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int tempY = y + dy[k];
                int tempX = x + dx[k];

                if(tempY >= 0 && tempY < N && tempX >= 0 && tempX < M){
                    if(!map[tempY][tempX] && copyMap[y][x] > 0){
                        copyMap[y][x]--;
                    }
                }
            }

            if(copyMap[y][x] > 0)
                q.push(make_pair(y, x));
        }

        memcpy(map, copyMap, sizeof(copyMap));

        // cout << "============" << endl;
        // for(int i = 0; i < N; i++){
        //     for(int j = 0;  j < M; j++){
        //         cout << map[i][j];
        //     }
        //     cout << endl;
        // }

        //내년 시작
        answer++;
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] != 0) q.push(make_pair(i, j)); 
        }
    }

    cout << BFS();
    return 0;
}