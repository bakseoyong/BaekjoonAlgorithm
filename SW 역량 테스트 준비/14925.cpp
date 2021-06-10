#include <iostream>
#include <cmath>
using namespace std;

int M, N;
int map[1001][1001];
int curLen = 0;

void BruteForce(int y, int x){

    while(1){
        int detCnt = 0;

        if(y + curLen >= M || x + curLen >= N) return;

        for(int i = y; i <= y + curLen; i++){
            for(int j = x; j <= x + curLen; j++){
                if(map[i][j] == 0) detCnt++;
                else return;
            }
        }

        if(detCnt == pow((curLen + 1), 2) ){
            curLen++;

        }else return;
        
    }
}

int main(){
    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            BruteForce(i, j);
        }
    }


    cout << curLen;


}