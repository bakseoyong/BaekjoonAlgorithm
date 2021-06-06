#include <iostream>
using namespace std;

string batch[5];
int answer = 0;
int dy[5] = {0, 0, 1, 0, -1};
int dx[5] = {0, -1, 0, 1, 0};
bool visited[5][5];

void DFS(int y, int x, int yCnt, int sCnt, int recurCnt){
    if(recurCnt == 7)
        if(yCnt < sCnt){
            answer++;
            return;
        }

    for(int k = 0; k < 5; k++){
        if(y + dy[k] >= 0 && y + dy[k] < 5 && x + dx[k] >= 0 && x + dx[k] < 5){
            if(!visited[y+dy[k]][x+dx[k]]){
                visited[y+dy[k]][x+dx[k]] = true;
                if(batch[y+dy[k]][x+dx[k]] == 'Y') DFS(y+dy[k], x+dx[k], yCnt + 1, sCnt, recurCnt + 1);
                else DFS(y+dy[k], x+dx[k], yCnt, sCnt + 1, recurCnt + 1);
                visited[y+dy[k]][x+dx[k]] = false;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        cin >> batch[i];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            DFS(i, j, 0, 0, 0);
        }
    }

    cout << answer;
}