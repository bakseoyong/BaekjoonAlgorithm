#include <iostream>
using namespace std;

int map[128][128];
int blueCnt = 0;
int redCnt = 0;

bool findBluePaper(int N, int y, int x){
    for(int i = y; i < y+N; i++){
        for(int j=x; j < x+N; j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}

bool findRedPaper(int N, int y, int x){
    for(int i = y; i < y+N; i++){
        for(int j=x; j < x+N; j++){
            if(map[i][j] == 1) return false;
        }
    }
    return true;
}


void recursive(int N, int y, int x){
    int pNum = N * N;
    bool a, b;
    a = findBluePaper(N, y, x);
    b = findRedPaper(N, y, x);

    if(a){
        blueCnt++;
        return;
    }
    else if(b){
        redCnt++;
        return;
    }else{ //a, b 둘 다 1일 가능성 X
        recursive(N/2, y, x);
        recursive(N/2, y, x+N/2);
        recursive(N/2, y+N/2, x);
        recursive(N/2, y+N/2, x+N/2);
    }
}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    recursive(N, 0, 0);

    cout << redCnt << endl;
    cout << blueCnt;
}