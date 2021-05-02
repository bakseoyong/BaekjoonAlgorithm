#include <iostream>
using namespace std;

int map[2187][2187];

int zero = 0;
int one = 0;
int minusOne = 0;


bool isZero(int N, int y, int x){
    for(int i =y; i < y + N; i++){
        for(int j = x; j < x + N; j++){
            if(map[i][j] != 0) return false;
        }
    }

    return true;
}

bool isOne(int N, int y, int x){
    for(int i =y; i < y + N; i++){
        for(int j = x; j < x + N; j++){
            if(map[i][j] != 1) return false;
        }
    }

    return true;
}

bool isMinusOne(int N, int y, int x){
    for(int i =y; i < y + N; i++){
        for(int j = x; j < x + N; j++){
            if(map[i][j] != -1) return false;
        }
    }

    return true;
}

void recursive(int N, int y , int x){
    bool a, b, c;
    a = isZero(N, y, x);
    b = isOne(N, y, x);
    c = isMinusOne(N, y, x);

    if(a){
        zero++;
        return;
    }else if(b){
        one++;
        return;
    }else if(c){
        minusOne++;
        return;
    }else{
        recursive(N/3, y, x);
        recursive(N/3, y, x+N/3);
        recursive(N/3, y, x+2*(N/3));
        recursive(N/3, y+N/3, x);
        recursive(N/3, y+N/3, x+N/3);
        recursive(N/3, y+N/3, x+2*(N/3));
        recursive(N/3, y+2*(N/3), x);
        recursive(N/3, y+2*(N/3), x+N/3);
        recursive(N/3, y+2*(N/3), x+2*(N/3));
    }
}

int main(){
    int N;
    cin >> N;

    for(int i =0 ; i < N; i++){
        for(int j =0; j < N; j++){
            cin >> map[i][j];
        }
    }

    recursive(N, 0, 0);

    cout << minusOne << endl <<  zero << endl << one;
}