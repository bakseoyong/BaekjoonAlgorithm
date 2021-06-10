#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef struct _xy{
    int x;
    int y;
} xy;

int N, M;
int map[10][10];
xy hole;
xy red;
xy blue;
bool visited[10][10][10][10];
int moveDir[4][2] = { //좌상우하 yx
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};
queue<tuple<int, xy, xy> > Q;
int answer = 11;


void Move(int dir, xy tr, xy tb, int cnt){
    xy ttr, ttb;

    ttr.y = tr.y; ttr.x = tr.x; ttb.y = tb.y; ttb.x = tb.x;

    while(map[tb.y][tb.x] != 1){
        tb.y += moveDir[dir][0];
        tb.x += moveDir[dir][1];

        if(tb.y == hole.y && tb.x == hole.x){
            //불필요한 시행
            return;
        }
    }

    while(map[tr.y][tr.x] != 1){
        tr.y += moveDir[dir][0];
        tr.x += moveDir[dir][1];

        if(tr.y == hole.y && tr.x == hole.x){
            break;
        }
    }

    //빨간 공이 결승점에 도착한 상태 || 빨간공과 파란공이 도착하지 않고 벽에 박혀있는 경우

    //공이 동일한 위치에 있는 경우
    if(tr.y == tb.y && tr.x == tb.x){
        if(ttb.x == ttr.x){ //상하 이동이였을 경우
            if(dir == 1){
                if(ttb.y > ttr.y) tb.y -= moveDir[dir][0] * 2; 
                else tr.y -= moveDir[dir][0] * 2;
            }else{
                if(ttb.y > ttr.y) tr.y -= moveDir[dir][0] * 2;
                else tb.y -= moveDir[dir][0] * 2;
            }

        }else if(ttb.y == ttr.y){
            if(dir == 0) {
                if(ttb.x > ttr.x) tb.x -= moveDir[dir][1] * 2;
                else tr.x -= moveDir[dir][1] * 2;
            }
            else{
                if(ttb.x > ttr.x) tr.x -= moveDir[dir][1] * 2;
                else tb.x -= moveDir[dir][1] * 2;
            }
        }
    }

    //공을 벽에서 빼주는 경우
    if(map[tr.y][tr.x] == 1){
        tr.y -= moveDir[dir][0]; tr.x -= moveDir[dir][1];
    }
    if(map[tb.y][tb.x] == 1){
        tb.y -= moveDir[dir][0]; tb.x -= moveDir[dir][1];
    }
    cout << "finish ry, rx : " << tr.y << " " << tr.x << " by, bx : " << tb.y << " " << tb.x << endl;

    if(visited[tr.y][tr.x][tb.y][tb.x] == false){
        Q.push(make_tuple(cnt, tr, tb));
        visited[tr.y][tr.x][tb.y][tb.x] = true;
    }
}

void BFS(){
    Q.push(make_tuple(0, red, blue));
    visited[red.y][red.x][blue.y][blue.x] = true;

    while(!Q.empty()){
        xy tr, tb;
        int visitCnt = get<0>(Q.front());
        tr.y = get<1>(Q.front()).y; tr.x = get<1>(Q.front()).x;
        tb.y = get<2>(Q.front()).y; tb.x = get<2>(Q.front()).x;
        Q.pop();

        cout << "ry, rx : " << tr.y << " " << tr.x << " by, bx : " << tb.y << " " << tb.x << endl;

        if(visitCnt > 10) continue;
        if(tr.y == hole.y && tr.x == hole.x) answer = min(answer, visitCnt);

        for(int k = 0; k < 4; k++){
            Move(k, tr, tb, visitCnt + 1);
        }
    }
}

int main(){
    string s;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            if(s[j] == '#') map[i][j] = 1;
            else if(s[j] == 'O') {
                map[i][j] = 2;
                hole.y = i; hole.x = j;
            }
            else{
                map[i][j] = 0;
                if(s[j] == 'R'){
                    red.y = i; red.x = j;
                }else if(s[j] == 'B'){
                    blue.y = i; blue.x = j;
                }
            }
        }
    }

    BFS();

    if(answer == 11){
        cout << -1; return 0;
    }
    cout << answer;
}