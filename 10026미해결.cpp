#include <iostream>
using namespace std;

void DFS(int painting[100][100], int y, int x, int N, int RGB){
    int dx = {-1, 0, 1, 0};
    int dy = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++){
        if(y + dy[i] < 0 || y + dy[i] >= N) continue;
        if(x + dx[i] < 0 || x + dx[i] >= N) continue;
        if(RGB)
    }
}

void weakDFS(int weakPainting[100][100], int y, int x, int N){

}

void copyPainting(int N, int painting[100][100], int weakPainting[100][100]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(painting[i][j] != 38)
                weakPainting[i][j] = painting[i][j];
            else
                weakPainting[i][j] = 38;
        }
    }
} 

int main(){
    int N;
    cin >> N;
    int painting[100][100];
    int weakPainting[100][100];
    int RGB;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> painting[i][j];
        }
    }

    copyPainting(N, painting, weakPainting);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            RGB = painting[i][j];
            DFS(painting, i, j, N, RGB);
        }
    }
}