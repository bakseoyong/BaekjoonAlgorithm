#include <iostream>
#include <queue>
#include <string.h>
#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3
#define UP 4
#define DOWN 5
#define EASTORDER 1
#define WESTORDER 2
#define SOUTHORDER 4
#define NORTHORDER 3

using namespace std;

int N, M, K;
int map[20][20];
queue<int> order; 
int dice[6] = { 0, };
int y, x;

bool afterOrder(int dir){
    int tempDice[6];
    int dx = x;
    int dy = y;
    memmove(tempDice, dice, sizeof(int) * 6);
    if(dir == EASTORDER){
        dx += 1;
        if(dx < 0 || dx >= M || dy < 0 || dy >= N)
            return false;
        dice[UP] = tempDice[EAST];
        dice[EAST] = tempDice[DOWN];
        dice[WEST] = tempDice[UP];
        dice[DOWN] = tempDice[WEST];
    }else if(dir == WESTORDER){
        dx -= 1;
        if(dx < 0 || dx >= M || dy < 0 || dy >= N)
            return false;
        dice[UP] = tempDice[WEST];
        dice[EAST] = tempDice[UP];
        dice[WEST] = tempDice[DOWN];
        dice[DOWN] = tempDice[EAST];
    }else if(dir == SOUTHORDER){
        dy += 1;
        if(dx < 0 || dx >= M || dy < 0 || dy >= N)
            return false;
        dice[UP] = tempDice[NORTH];
        dice[NORTH] = tempDice[DOWN];
        dice[DOWN] = tempDice[SOUTH];
        dice[SOUTH] = tempDice[UP];
    }else if(dir == NORTHORDER){
        dy -= 1;
        if(dx < 0 || dx >= M || dy < 0 || dy >= N)
            return false;
        dice[UP] = tempDice[SOUTH];
        dice[SOUTH] = tempDice[DOWN];
        dice[DOWN] = tempDice[NORTH];
        dice[NORTH] = tempDice[UP];
    }

    //만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다
    

    x = dx;
    y = dy;
    return true;
}

void DICE(){

    while(!order.empty()){
        int dir = order.front();
        order.pop();

        if(afterOrder(dir)){
            if(map[y][x] == 0){
                map[y][x] = dice[DOWN];
            }else{
                dice[DOWN] = map[y][x];
                map[y][x] = 0;
            }
            
            cout << dice[UP] << endl;
        }
    }
}

int main(){
    cin >> N >> M >> y >> x >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    int a;
    for(int i = 0; i < K; i++){
        cin >> a;
        order.push(a);
    }

    DICE();
}