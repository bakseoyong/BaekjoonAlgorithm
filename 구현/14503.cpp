#include <iostream>
using namespace std;

int N, M;
int map[50][50];
int r, c, d;
int dy[4] = {-1, 0, 1, 0}; //북 동 남 서 방향
int dx[4] = {0, 1, 0, -1};
int answer = 0;

int lookLeft(int dir){
    if(dir == 0)
        dir = 3;
    else
        dir -= 1;

    return dir;
}

int lookBack(int dir){
    if(dir == 0 || dir == 1)
        dir += 2;
    else
        dir -= 2;

    return dir;
}

//재귀함수 X => while문 사용
//d 조건 => 이미 청소한 구역, 벽 구별 필요 
void cleanRoom(){
    //맨 처음 접근했을 때
    int y = r;
    int x = c;
    int dir = d;
    bool isEnd = false;

    while(!isEnd){

        int dirCnt = 0;

        //1. 해당 위치를 청소한다.
        if(map[y][x] == 0){ //후진해서 돌아온 경우, 1을 시행하지 않는다.
            map[y][x] = 2; // 2 == 청소한 구역

            //정답 카운트 추가.
            answer++;
        }

        //2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
        //북 => 서, 동 => 북, 남 => 동, 서 => 남
    

        //왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면
        while(dirCnt <= 3){
            dir = lookLeft(dir);
            dirCnt++;
            int dirX = x + dx[dir];
            int dirY = y + dy[dir];

            if(dirY >= 0 && dirY < N && dirX >= 0 && dirX < M && map[dirY][dirX] == 0){
                dirCnt = 999; //그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다
                y = dirY;
                x = dirX;
                //cout << "y :  " << y << " x : " << x << endl;
            }
            //왼쪽 방향에 청소할 공간이 없다면
            else{
                //네 방향 모두 청소가 이미 되어있거나 벽인 경우
                if(dirCnt == 4){
                    //뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다
                    //0 => 2, 1 => 3, 2 => 0, 3 => 1
                    dir = lookBack(dir);
                    if(map[y+dy[dir]][x+dx[dir]] == 1){
                        dirCnt = 999;
                        isEnd = true;
                    }
                    else{ //바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다
                        dirCnt = 999;
                        y = y+dy[dir];
                        x = x+dx[dir];
                        dir = lookBack(dir);
                    }
                }
            }

        }
    }
}

int main(){
    cin >> N >> M;

    cin >> r >> c >> d;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    cleanRoom();

    cout << answer;
}