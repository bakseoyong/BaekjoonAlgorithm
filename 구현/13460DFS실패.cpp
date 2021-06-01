#include <iostream>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

typedef struct _position{
    int y;
    int x;
} position;

int N, M;
char board[10][10];
position rB, bB;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 11; //정답
bool redGoal = false;
bool blueGoal = false;
position tempRRB, tempBBB;

void copyBoard(char dest[10][10], char resource[10][10]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j< M; j++){
            dest[i][j] = resource[i][j];
        }
    }
}

void move(int dir, position rrB, position bbB){ //board와 move를 위한 board를 구분해야 한다.
    

    //맨 처음 시행
    if(dir == -1) {
        tempRRB.y = rrB.y; 
        tempRRB.x = rrB.x;
        tempBBB.y = bbB.y;
        tempBBB.x = bbB.x;
        return;
    }

    board[rrB.y][rrB.x] = 'R';
    board[bbB.y][bbB.x] = 'B';

    while(board[rrB.y + dy[dir]][rrB.x + dx[dir]] != '#' && board[rrB.y + dy[dir]][rrB.x + dx[dir]] != 'B'){
        if(board[rrB.y][rrB.x] != 'O'){
            board[rrB.y][rrB.x] = '.';
        }
        if(board[rrB.y + dy[dir]][rrB.x + dx[dir]] != 'O'){
            board[rrB.y + dy[dir]][rrB.x + dx[dir]] = 'R';
        }
        rrB.y += dy[dir];
        rrB.x += dx[dir];
        //중간중간 구멍에 들어갔는지 확인
        if(board[rrB.y][rrB.x] == 'O'){
            //cout << "!!!! : dir :" << dir << endl;
            redGoal = true;
        }
    }

    while(board[bbB.y + dy[dir]][bbB.x + dx[dir]] != '#' && board[bbB.y + dy[dir]][bbB.x + dx[dir]] != 'R'){
        if(board[rrB.y][rrB.x] != 'O'){
            board[rrB.y][rrB.x] = '.';
        }
        if(board[rrB.y + dy[dir]][rrB.x + dx[dir]] != 'O'){
            board[rrB.y + dy[dir]][rrB.x + dx[dir]] = 'B';
        }
        bbB.y += dy[dir];
        bbB.x += dx[dir];
        if(board[bbB.y][bbB.x] == 'O'){
            //cout << "???? : dir :" << dir << endl;
            //cout << "============" << endl;
            blueGoal = true;
        }
    }

    tempRRB.y = rrB.y; 
    tempRRB.x = rrB.x;
    tempBBB.y = bbB.y;
    tempBBB.x = bbB.x;

    //테이블에 R, B를 .으로 만들어버리고 , 새로 들어올때 R, B를 찍어주자.
    board[tempRRB.y][tempRRB.x] = '.';
    board[tempBBB.y][tempBBB.x] = '.';
}

//연산 횟수를 줄이기 위해 이전에 시행한 방향과 똑같이 가는건 연산에 포함X
void startLink(int dir, position rrB, position bbB, int moveCnt){
    //연산 횟수가 10번을 넘겼다면, 이 분기는 필요없는 분기
    if(moveCnt > 11) //움직이기 전에 moveCnt를 먼저 올리므로 11
        return;
    else{
        blueGoal = false;
        redGoal = false;

        //이동하고
        move(dir, rrB, bbB);

        rrB.y = tempRRB.y;
        rrB.x = tempRRB.x;
        bbB.y = tempBBB.y;
        bbB.x = tempBBB.x;

        
        if(blueGoal == true){
            return;
        }
        if(redGoal == true && blueGoal == false){
            //cout << "!" << endl;
            if(answer > moveCnt) answer = moveCnt;
        }
        
        
        //다음에 어느방향으로 갈지
        startLink(UP, rrB, bbB, moveCnt + 1);
        startLink(DOWN, rrB, bbB,  moveCnt + 1);
        startLink(LEFT, rrB, bbB,  moveCnt + 1);
        startLink(RIGHT, rrB, bbB,  moveCnt + 1);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                rB.y = i;
                rB.x = j;
            }else if(board[i][j] == 'B'){
                bB.y = i;
                bB.x = j;
            }
        }
    }

    //cout << rB.y << rB.x << bB.y << bB.x << endl;
    startLink(-1, rB, bB, 0);

    //전체 분기에서 구멍에 도달하는 방법을 찾지 못한 경우
    if(answer == 11){
        cout << -1;
        return 0;
    }else{
        cout << answer;
    }
}