#include <iostream>
#include <malloc.h>
using namespace std;

char** map;

bool isZero(int N, int y, int x){
    for(int i =y; i < y+N; i++){
        for(int j = x; j < x+N; j++){
            if(map[i][j] == '1') return false;
        }
    }

    return true;
}

bool isOne(int N, int y, int x){
    for(int i =y; i < y+N; i++){
        for(int j = x; j < x+N; j++){
            if(map[i][j] == '0') return false;
        }
    }

    return true;
}

void recursive(int N, int y, int x){
    bool zero, one;

    zero = isZero(N, y, x);
    one = isOne(N, y, x);
    
    if(zero) cout << 0;
    else if(one) cout << 1;
    else{
        cout << "(";
        recursive(N/2, y, x);
        recursive(N/2, y, x+N/2);
        recursive(N/2, y+N/2, x);
        recursive(N/2, y+N/2, x+N/2);
        cout << ")";
    }
}

int main(){
    int N;
    cin >> N;

    map = (char**)malloc(sizeof(char*)*N);

    for(int i = 0; i <N; i++){
        map[i] = (char*)malloc(sizeof(char)*N);
        cin >> map[i];
    }

    recursive(N, 0, 0);
}