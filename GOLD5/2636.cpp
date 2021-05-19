#include <iostream>
#include <queue>
using namespace std;

int col, row;
int cnt = 0;
int day = 0;
int map[100][100];
int visited[100][100] = { 0, };
int lastDayCheeseNum;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int y, int x){
    queue<pair<int, int> > bfsQueue;

    bfsQueue.push(make_pair(y, x));

    while(!bfsQueue.empty()){
        y = bfsQueue.front().first;
        x = bfsQueue.front().second;
        bfsQueue.pop();

        for(int k = 0; k < 4; k++){
            if(y+dy[k] < 0 || y+dy[k] >= col) continue;
            if(x+dx[k] < 0 || x+dx[k] >= row) continue;
            if(map[y+dy[k]][x+dx[k]] == 0 && visited[y+dy[k]][x+dx[k]] == 0){
                map[y+dy[k]][x+dx[k]] = 3;
                visited[y+dy[k]][x+dx[k]] = 1;
                bfsQueue.push(make_pair(y+dy[k], x+dx[k]));
            }            
        }
    }
}

void detectDisappearCheese(){

    for(int y = 0; y < col; y++){
        for(int x = 0; x < row; x++){
            if(map[y][x] == 1){
                for(int k = 0; k < 4; k++){
                    if(y+dy[k] < 0 || y + dy[k] >= col) continue;
                    if(x+dx[k] < 0 || x + dx[k] >= row) continue;
                    if(map[y+dy[k]][x+dx[k]] == 3 && map[y][x] == 1){
                        map[y][x] = 2;
                    }
                }
            }
        }
    }
}

void disappearCheese(){
    day++;
    
    lastDayCheeseNum = cnt;

    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            if(map[i][j] == 2){
                map[i][j] = 3;
                //치즈안에 공기 확인
                for(int k = 0; k < 4; k++){
                    if(i +dy[k] < 0 || i + dy[k] >= col) continue;
                    if(j + dx[k] < 0 || j + dx[k] >= row) continue;
                    if(map[i+dy[k]][j+dx[k]] == 0){
                        BFS(i+dy[k], j+dx[k]);
                    }
                }
                cnt--;
            }
        }
    }

    //cout << "day : " << day << "cnt : " << cnt << endl;

}

int main(){
    cin >> col >> row;

    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) cnt++;
        }
    }    
    

    BFS(0, 0);

    while(cnt != 0){
        detectDisappearCheese();
        disappearCheese();
    }

    cout << day << endl << lastDayCheeseNum;
}