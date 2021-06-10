#include <iostream>
using namespace std;

int N;
int guiltyMap[17][17] = { 0, };
int playerGlt[17];
int mafiaNum;

void night(){
    //마피아가 유죄 지수가 가장 높지 않으면 됨.
    //짝수명
    //유죄 지수의 변경
    

    for(int i = 0; i < N; i++){
        //i번을 죽였을때 각 플레이어의 유죄지수

    }
}

void solution(){
    night();
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> playerGlt[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> guiltyMap[i][j];
        }
    }

    cin >> mafiaNum;

    solution();
}