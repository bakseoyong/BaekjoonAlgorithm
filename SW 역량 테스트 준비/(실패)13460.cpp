#include <iostream>
using namespace std;

typedef struct _ballPos{
    int y;
    int x;
} ballPos;

typedef struct _tempSavePos{
    int ry;
    int rx;
    int by;
    int bx;
} tempSavePos;

int N, M;
char ballExit[10][10];
int answer = 11;
ballPos redBall;
ballPos blueBall;

void LeftMove(int recCnt){
    int tempRedBallX = redBall.x;
    int tempBlueBallX = blueBall.x;
    bool isRedBallGoal;
    bool isBlueBallGoal;

    while(redBall.x != '#'){
        redBall.x -= 1;
        if(ballExit[redBall.y][redBall.x] == 'O') isRedBallGoal = true;

    }

    while(blueBall.x != '#'){
        blueBall.x -= 1;
        if(ballExit[redBall.y][redBall.x] == 'O') isBlueBallGoal = true;

    }

    if(redBall.y == blueBall.y){
        if(redBall.x == blueBall.x){
            if(tempRedBallX > tempBlueBallX){
                redBall.x += 2;
                blueBall.x += 1;
            }else{
                blueBall.x += 2;
                redBall.x += 1;
            }
        }
    }else{
        redBall.x += 1;
        blueBall.x += 1;
    }

    if(isRedBallGoal == true && isBlueBallGoal == false) answer = min(answer, recCnt);

}

void RightMove(int recCnt){
    int tempRedBallX = redBall.x;
    int tempBlueBallX = blueBall.x;
    bool isRedBallGoal;
    bool isBlueBallGoal;

    while(redBall.x != '#'){
        redBall.x += 1;
        if(ballExit[redBall.y][redBall.x] == 'O') isRedBallGoal = true;

    }

    while(blueBall.x != '#'){
        blueBall.x += 1;
        if(ballExit[redBall.y][redBall.x] == 'O') isBlueBallGoal = true;

    }

    if(redBall.y == blueBall.y){
        if(redBall.x == blueBall.x){
            if(tempRedBallX > tempBlueBallX){
                redBall.x -= 1;
                blueBall.x -= 2;
            }else{
                blueBall.x -= 1;
                redBall.x -= 2;
            }
        }
    }else{
        redBall.x -= 1;
        blueBall.x -= 1;
    }

    if(isRedBallGoal == true && isBlueBallGoal == false) answer = min(answer, recCnt);

}

void UpMove(int recCnt){
    int tempRedBallY = redBall.y;
    int tempBlueBallY = blueBall.y;
    bool isRedBallGoal;
    bool isBlueBallGoal;

    while(redBall.y != '#'){
        redBall.y -= 1;

        if(ballExit[redBall.y][redBall.x] == 'O') isRedBallGoal = true;
    }

    while(blueBall.y != '#'){
        blueBall.y -= 1;

        if(ballExit[redBall.y][redBall.x] == 'O') isBlueBallGoal = true;
    }

    if(redBall.x == blueBall.x){
        if(redBall.y == blueBall.y){
            if(tempRedBallY > tempBlueBallY){
                redBall.y += 1;
                blueBall.y += 2;
            }else{
                blueBall.y += 1;
                redBall.y += 2;
            }
        }
    }else{
        redBall.y += 1;
        blueBall.y += 1;
    }

    if(isRedBallGoal == true && isBlueBallGoal == false) answer = min(answer, recCnt);
}

void DownMove(int recCnt){
    int tempRedBallY = redBall.y;
    int tempBlueBallY = blueBall.y;
    bool isRedBallGoal;
    bool isBlueBallGoal;

    while(redBall.y != '#'){
        redBall.y += 1;
        if(ballExit[redBall.y][redBall.x] == 'O') isRedBallGoal = true;

    }

    while(blueBall.y != '#'){
        blueBall.y += 1;
        if(ballExit[redBall.y][redBall.x] == 'O') isBlueBallGoal = true;

    }

    if(redBall.x == blueBall.x){
        if(redBall.y == blueBall.y){
            if(tempRedBallY > tempBlueBallY){
                redBall.y -= 2;
                blueBall.y -= 1;
            }else{
                blueBall.y -= 2;
                redBall.y -= 1;
            }
        }
    }else{
        redBall.y -= 1;
        blueBall.y -= 1;
    }

    if(isRedBallGoal == true && isBlueBallGoal == false) answer = min(answer, recCnt);

}

void Move(int recCnt){

    if(recCnt == 11) return;

    tempSavePos tSP;
    tSP.bx = blueBall.x;
    tSP.by = blueBall.y;
    tSP.rx = redBall.x;
    tSP.ry = redBall.y;

    LeftMove(recCnt + 1);
    Move(recCnt + 1);
    redBall.y = tSP.ry;
    redBall.x = tSP.rx;
    blueBall.y = tSP.by;
    blueBall.x = tSP.bx;

    RightMove(recCnt + 1);
    Move(recCnt + 1);
    redBall.y = tSP.ry;
    redBall.x = tSP.rx;
    blueBall.y = tSP.by;
    blueBall.x = tSP.bx;

    UpMove(recCnt + 1);
    Move(recCnt + 1);
    redBall.y = tSP.ry;
    redBall.x = tSP.rx;
    blueBall.y = tSP.by;
    blueBall.x = tSP.bx;

    DownMove(recCnt + 1);
    Move(recCnt + 1);
    redBall.y = tSP.ry;
    redBall.x = tSP.rx;
    blueBall.y = tSP.by;
    blueBall.x = tSP.bx;

}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> ballExit[i][j];
        }
    }

    Move(0);

    cout << answer;

}