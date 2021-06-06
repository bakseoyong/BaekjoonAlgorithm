#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define SOM 1
#define YEON 0
using namespace std;

int answer = 0;
int map[5][5];
bool visited[25];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> V;

bool isAttach(){
    bool attachVisited[5][5];
    memset(attachVisited, false, sizeof(attachVisited));
    int attachCnt = 0;
    queue<pair<int, int> >  Q;

    for(int i = 0; i < 25; i++){
        if(visited[i] && Q.empty()){
            Q.push(make_pair(i/5, i%5));
            attachVisited[i/5][i%5] = true;
            attachCnt++;
        }
    }

    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int k = 0; k < 4; k++){
            if(y+dy[k] >= 0 && y + dy[k] < 5 && x + dx[k] >= 0 && x + dx[k] < 5){
                if(attachVisited[y+dy[k]][x+dx[k]] == false && visited[(y+dy[k]) * 5 + (x+dx[k]) ] == true){
                    attachVisited[y+dy[k]][x+dx[k]] = true;
                    attachCnt++;

                    Q.push(make_pair(y+dy[k], x+dx[k]));
                }    
            }
        }
    }

    
    if(attachCnt == 7) return true;
    return false;
}

bool isSMoreThanFour(){
    int cnt = 0;

    for(int i = 0; i < 25; i++){
        if(visited[i]){
            if(map[i/5][i%5] == SOM){
                cnt++;
            }
        }
    }

    if(cnt > 3){
        if(isAttach()) {
            
            return true;
        }
    }

    return false;

}

void DFS(int recCnt, int idx){

    if(recCnt == 7){
        //cout << "rec order : ";
        //for(int i =)
        //cout << endl;
        if(isSMoreThanFour()) answer++;
        return;
    }

    for(int i = idx; i < 25; i++){
            if(visited[i]) continue;

            visited[i] = true;
            DFS(recCnt + 1, i);
            visited[i] = false;
    }

}

int main(){
    char c;
    for(int i = 0 ; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> c;
            if(c == 'Y') map[i][j] = YEON;
            else map[i][j] = SOM;
        }
    }

    DFS(0, 0);

    cout << answer;
}