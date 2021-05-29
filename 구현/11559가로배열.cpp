#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[12][6];
char map[12][6];
int puyoStack[12] = { 0, };
//큐에서 빼낼 때 visited도 초기화 시켜줘야 한다.
queue<pair<int, int> > q;


void DFS(int y, int x, char color){
    for(int k = 0; k < 4; k++){
        if(map[y+dy[k]][x+dx[k]] != color || y+dy[k] > 11 || y+dy[k] < 0 ||
        x + dx[k] > 5 || x + dx[k] < 0 || visited[y+dy[k]][x+dx[k]] == true) 
            continue;
        else{
            q.push(make_pair(y+dy[k], x+dx[k]));
            visited[y+dy[k]][x+dx[k]] = true;
            DFS(y+dy[k], x+dx[k], color);
        }
    }
}

int main(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 11; i >= 0; i--){
        for(int j = 0; j < 6; j++){
            if(map[i][j] != '.'){
                DFS(i, j, map[i][j]);

                //탐색된 개수가 4개 이상이라면 ,(임시문자)로 설정한 후,
                if(q.size() >= 4){
                    while(!q.empty()){
                        int tempY = q.front().first;
                        int tempX = q.front().second;
                        //visited 초기화
                        visited[tempY][tempX] = false;
                        q.pop();

                        map[tempY][tempX] = ',';
                        puyoStack[tempY]++;
                    }
                }
                //실시간으로 뿌요를 내리면 좌표값에 혼동
                //위에 뿌요가 있다면 내려보낸다.
                for(int t = 0; t < 6; t++){
                    for(int r = 11; r >= 0; r--){
                        if(map[r][t])
                    }
                }
            }
        }
    }

    // DFS(11, 0, map[11][0]);
    // cout << q.size();
}