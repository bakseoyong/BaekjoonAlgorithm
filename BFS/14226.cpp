#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int S;
int dp[1002][1002]; //dp[1] = 이모티콘 1개일때 걸리는 시간 저장 + S가 1000일 경우 1001 - 1 인 경우도 생각해야 된다.
queue<pair<int, int> > q;

void BFS(int time){

    while(!q.empty()){
        int screen = q.front().first;
        int clipboard = q.front().second;
        int timeFlow = dp[screen][clipboard] + 1;
        q.pop();

        if(screen <= 0 || screen >= S + 2 || screen + clipboard > 1001) continue; // S + 1은 3번의 경우 때문에 가능

        //1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        if(dp[screen][screen] > timeFlow){
            dp[screen][screen] = timeFlow;
            q.push(make_pair(screen, screen));
        }
        //2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        if(dp[screen + clipboard][clipboard] > timeFlow){
            dp[screen + clipboard][clipboard] = timeFlow;
            q.push(make_pair(screen + clipboard, clipboard));
        }
        //3. 화면에 있는 이모티콘 중 하나를 삭제한다.
        if(dp[screen - 1][clipboard] > timeFlow){
            dp[screen - 1][clipboard] = timeFlow;
            q.push(make_pair(screen - 1, clipboard));
        }
        
    }
}

int main(){
    int answer = 999999;
    cin >> S;

    q.push(make_pair(1, 1));
    memset(dp, 999999, sizeof(dp));
    dp[1][1] = 1;

    BFS(S + 1);
    
    for(int i = 1; i <= 1001; i++){
        if(dp[S][i] != 999999){
            answer = min(answer, dp[S][i]);
        }
    }
    
    cout << answer;
}