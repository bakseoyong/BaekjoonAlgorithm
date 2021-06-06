#include <iostream>
#include <queue>
using namespace std;

int A, B, N, M;
bool visited[100001];

int main(){
    int day = 0;
    cin >> A >> B >> N >> M;
    queue<int> q;
    bool isEnd = false;

    q.push(N);
    visited[N] = true;
    while(1){
        int queueSize = q.size();
        int curPos;

        for(int i = 0; i < queueSize; i++){
            curPos = q.front();
            q.pop();

            if(curPos == M){
                isEnd = true;
                break;
            }

            if(curPos - 1 >= 0 && !visited[curPos - 1]) {
                q.push(curPos - 1);
                visited[curPos -1] = true;
            }
            if(curPos + 1 >= 0 && curPos + 1 < 100001 && !visited[curPos + 1]){
                q.push(curPos + 1);
                visited[curPos + 1] = true;
            }
            if(curPos - A >= 0 && !visited[curPos - A]){
                q.push(curPos - A);
                visited[curPos - A] = true;
            } 
            if(curPos + A < 100001 && !visited[curPos + A]){
                q.push(curPos + A);
                visited[curPos + A] = true;
            }
            if(curPos - B >= 0 && !visited[curPos - B]){
                q.push(curPos - B);
                visited[curPos - B] = true;
            } 
            if(curPos + B < 100001 && !visited[curPos + B]){
                q.push(curPos + B);
                visited[curPos + B] = true;
            }
            if(curPos * A < 100001 && !visited[curPos * A]){
                q.push(curPos * A);
                visited[curPos * A] = true;
            }
            if(curPos * B < 100001 && !visited[curPos * B]){
                q.push(curPos * B);
                visited[curPos * B] = true;
            }
        }

        if(isEnd == true){
            cout << day;
            return 0;
        }

        day++;
    }

}