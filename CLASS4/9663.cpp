#include <iostream>
#include <queue>
using namespace std;

int col[15];
int N;
int queenStack = 0;

void recursive(int cnt){
    if(cnt == N){
        queenStack++;
        return;
    }

    queue<int> tempQ;

    //cnt 이전까지의 퀸 위치값들을 큐에 저장
    for(int i = 0; i < cnt; i++){
        tempQ.push(col[i]);
    }

    //대각선 파악하기
    int j =1;
    for(int i = cnt-1; i >= 0; i--){ //cnt = 2 cnt-1 =  1 > 0
        if(col[i] - j >= 0) {
            //cout << col[i] -j << "push up" << endl;
            tempQ.push(col[i] - j);
        }
        if(col[i] + j < N)
            tempQ.push(col[i] + j);
        j++;
    }

    int isImpossible[15] = { 0, };

    //tempQ에 없는 값들만 뽑아서 다음 재귀호출 실행
    while(!tempQ.empty()){
        isImpossible[tempQ.front()] = 1;
        tempQ.pop();
    }

    //cout << "ispossible" << endl;
    // for(int i = 0; i < N; i++){
    //     cout << isImpossible[i] << " ";
    // }
    // cout << endl;

    for(int i = 0; i < N; i++){
        if(isImpossible[i] == 0){
            col[cnt++] = i;
            recursive(cnt);
            cnt--;
        }
    }


    return;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        //cout << "next" << endl;
        col[0] = i;
        recursive(1);
    }

    cout << queenStack;
}