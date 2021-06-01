// 뱀을 큐로 만들어줘야 한다.
#include <iostream>
#include <vector>
#include <map>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define APPLE 5
#define SNAKE 6
using namespace std;


int N, K, L;
int gameMap[101][101];
map<int, char> transTime;
bool isEnd = false;


bool strechHead(int pos, int y, int x){
    if(pos == RIGHT) x += 1;
    else if(pos == LEFT) x -= 1;
    else if(pos == UP) y -= 1;
    else if(pos == DOWN) y += 1;

    //늘린 머리가 벽과 부딪힌다면
    if(x < 0 || x > N || y < 0 || y > N){
        isEnd = true; //게임 끝내기
        return false;
    }


    if(gameMap[y][x] == APPLE){ //머리를 늘린 자리에 사과가 있다면
        gameMap[y][x] = SNAKE;
        return true;
    }
}

void GAME(){
    int x = 1;
    int y = 1;
    int sec = 0;
    //LEFT == 1, RIGHT == 2, UP == 3, DOWN == 4
    int pos = RIGHT;
    bool isMove = false;

    while(!isEnd){
        gameMap[y][x] = SNAKE;

        if(transTime.find(sec) != transTime.end()){ //해당 sec를 key값으로 가지고 있다면

        }else{
            //먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
            isMove = strechHead(pos, y, x);
            만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
            if(isMove){ //사과를 먹지 못했다면 꼬리는 움직여야 한다.
                
            }else{ //이동하지 못했다면, 왜 이동 못했는지 확인한다.(머리가 벽에 부딪힌 경우, 사과를 먹은 경우)

            }
            만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        }

        //작업이 끝나면 초가 증가
        sec++;
    }
}

int main(){
    int a, b;
    char c;
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        gameMap[a][b] = APPLE;
    }

    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> a >> c;
        transTime.insert(make_pair(a, c));
    }

    GAME();
}