#include <iostream>
#include <cmath>
using namespace std;

int M, N;
int map[1002002];
int curLen = 0;

void BruteForce(int idx){
    int y = idx / N;
    int x = idx % N;

    while(1){
        int detCnt = 0;

        for(int i = 0; i < curLen + 1; i++){
            for(int j = 0; j < curLen + 1; j++){
                if((y+i) * N + (x+j) > )
                if(map[(y+i) * N + (x+j)] == 0) detCnt++;
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

    for(int i = 0; i < M * N; i++){
        cin >> map[i];
    }

    for(int i = 0; i < M * N; i++){
        BruteForce(i);
    }

    cout << curLen * curLen << endl;


}