#include <iostream>
using namespace std;

int N;
int map[100001][3] = { 0, };
int minDp[100001][3] = { 0, };
int maxDp[100001][3] = { 0, };

void A(int y, int x){
    

    minDp[y][x] = maxDp[y][x] = map[y][x];
    if(y == 0) return;

    if(x == 0){
        minDp[y][x] += min(minDp[y-1][0], minDp[y-1][1]);
        maxDp[y][x] += max(maxDp[y-1][0], maxDp[y-1][1]);
    }else if(x == 1){
        minDp[y][x] += min(minDp[y-1][0], min(minDp[y-1][1], minDp[y-1][2]));
        maxDp[y][x] += max(maxDp[y-1][0], max(maxDp[y-1][1], maxDp[y-1][2]));
    }else if(x == 2){
        minDp[y][x] += min(minDp[y-1][1], minDp[y-1][2]);
        maxDp[y][x] += max(maxDp[y-1][1], maxDp[y-1][2]);
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> map[i][j];
            A(i, j);
        }
    }

    int answerMin = min(minDp[N-1][0], min(minDp[N-1][1], minDp[N-1][2]));
    int answerMax = max(maxDp[N-1][0], max(maxDp[N-1][1], maxDp[N-1][2]));

    cout << answerMax << " " << answerMin;
}