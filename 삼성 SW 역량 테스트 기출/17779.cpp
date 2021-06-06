#include <iostream>
using namespace std;

int N;
int map[21][21];

void findBoundary(int y, int x){
    int i = 0;
    int j = 0;
    int maxValue = N - 
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            findBoundary(i, j);
        }
    }
}