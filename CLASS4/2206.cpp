#include <iostream>
using namespace std;

int Y, X;
char map[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 987654321;

void DFS(int yy, int xx, int cnt, int stack){
    if(answer < stack) return; //아직 결승점에 도착하지 않았는데 이전 연산에 의한 최소 경로보다 벌써 길면 더이상 탐색하지 않는다.
    
    if(yy == Y -1 && xx == X - 1){
        answer = min(answer, stack);
        return;
    }

    for(int k = 0; k < 4; k++){
        if(map[yy+dy[k]][xx+dx[k]] == '0')
            DFS(yy+dy[k], xx+dx[k], cnt, stack + 1);
        else if(map[yy+dy[k]][xx+dx[k]] == '1' && cnt == 0){
            DFS(yy+dy[k], xx+dx[k], cnt + 1, stack + 1);
        }
        else return;
    }
}

int main(){
    cin >> Y >> X;

    for(int i = 0; i < Y; i++){
        cin >> map[i][0];
    }

    cout << map[1][0] << endl;

    DFS(0, 0, 0, 1);

    cout << answer;
}