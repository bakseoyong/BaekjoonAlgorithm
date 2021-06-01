#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define APPLE 5
using namespace std;

typedef struct _HEAD{
    int y;
    int x;
} HEAD;

int N, K, L;
int gameMap[101][101] = { 0, };
map<int, char> transTime;
deque<pair<int, int> > snake;
bool isEnd = false;
HEAD head;
int snakeLength = 1;

int nextPos(int pos, char isLeftRight){
    if(pos == RIGHT){
        if(isLeftRight == 'L')
            pos = UP;
        else
            pos = DOWN;
    }
    else if(pos == LEFT){
        if(isLeftRight == 'L')
            pos = DOWN;
        else
            pos = UP;
    }
    else if(pos == UP){
        if(isLeftRight == 'L')
            pos = LEFT;
        else
            pos = RIGHT;
    }
    else{
        if(isLeftRight == 'L')
            pos = RIGHT;
        else
            pos = LEFT;
    }

    return pos;
}

bool strechHead(int pos){
    
    if(pos == RIGHT) head.x += 1;
    else if(pos == LEFT) head.x -= 1;
    else if(pos == UP) head.y -= 1;
    else if(pos == DOWN) head.y += 1;

    snake.push_front(make_pair(head.y, head.x)); //deque의 앞 부분에 머리 추가
    snakeLength++;

    //늘린 머리가 벽과 부딪힌다면
    if(head.x < 1 || head.x > N || head.y < 1 || head.y > N){
        isEnd = true; //게임 끝내기
        return false;
    }

    //자기 자신의 몸과 부딪힌다면 (머리 좌표 제외)
    for(int i = 1; i < snakeLength; i++){
        if(snake[i].first == head.y && snake[i].second == head.x){
            isEnd = true;
            return false;
        }
    }

    if(gameMap[head.y][head.x] == APPLE){ //머리를 늘린 자리에 사과가 있다면
        gameMap[head.y][head.x] = 0;
        return false;
    }

    //사과가 없다면
    snakeLength--;
    return true;
    
}


int GAME(){
    int sec = 0;
    int pos = RIGHT;
    bool isMove = false;

    while(!isEnd){
        //초가 증가하면 작업이 시작된다
        sec++;

        //먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        isMove = strechHead(pos);
        if(isMove){ //사과를 먹지 못했다면 꼬리는 움직여야 한다.
            snake.pop_back();
        }else if(isEnd){ //이동하지 못했다면, 왜 이동 못했는지 확인한다.(머리가 벽에 부딪힌 경우, 사과를 먹은 경우)
            break; //머리가 벽에 부딪힌 경우
        }

        if(transTime.find(sec) != transTime.end()){ //해당 sec를 key값으로 가지고 있다면
            cout << sec << " ";
            char isLeftRight = transTime[sec];
            pos = nextPos(pos, isLeftRight);
            cout << "nextPos : " << pos << " stackLength :: " << snakeLength << endl;
            for(int i = 0; i < snakeLength; i++){
                cout << snake[i].first << " " << snake[i].second << endl;
            }
            cout << endl;
        }

    }

    return sec;
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

    snake.push_back(make_pair(1,1));
    head.y = 1;
    head.x = 1;

    cout << GAME();
}