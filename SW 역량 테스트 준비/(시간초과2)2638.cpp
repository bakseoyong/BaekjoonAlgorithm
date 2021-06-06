#include <iostream>
#include <queue>
#include <cstring>
#define CHEESE 1
#define AIR 2
#define SOONAIR 3
using namespace std;

int N, M;
int map[100][100];
queue<pair<int , int > > Q;
int moveArr[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
queue<pair<int, int> > CQ;
int answer = 0;

void BFS1(){
    int y, x, dy, dx;
    while(!Q.empty()){
        y = Q.front().first;
        x = Q.front().second;
        Q.pop();

        for(int k = 0; k < 4; k++){
            dy = y + moveArr[k][0];
            dx = x + moveArr[k][1];

            if(dy >= 0 && dy < N && dx >= 0 && dx < N){
                if(map[dy][dx] == 0){
                    map[dy][dx] = AIR;
                    Q.push(make_pair(dy, dx));
                }
            }
        }
    }
}

void BFS2(){
    int CQSize;
    int y, x, dy, dx;
    
    while(!CQ.empty()){
        CQSize = CQ.size();

        for(int i = 0; i < CQSize; i++){
            y = CQ.front().first;
            x = CQ.front().second;
            CQ.pop();

            int disCnt = 0;
            for(int k = 0; k < 4; k++){
                dy = y + moveArr[k][0];
                dx = x + moveArr[k][1];

                if(dy >= 0 && dy < N && dx >= 0 && dx < M){
                    if(map[dy][dx] == AIR){
                        disCnt++;
                    }
                }
            }
            
            if(disCnt >= 2) {
                map[y][x] = SOONAIR;
                Q.push(make_pair(y, x));
            }
            else CQ.push(make_pair(y, x));
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == SOONAIR)
                    map[i][j] = AIR;
            }
        }
        BFS1();
        
        answer++;
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == CHEESE)
                CQ.push(make_pair(i, j));
        }
    }

    Q.push(make_pair(0, 0));
    map[0][0] = AIR;
    BFS1();

    BFS2();

    cout << answer;
}