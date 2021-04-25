#include <iostream>
#include <string.h>

using namespace std;

int findMaximumHeight(int N, int map[100][100]){
    int maximumHeight = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(maximumHeight < map[i][j]) maximumHeight = map[i][j];
        }
    }

    return maximumHeight;
}

void copyMap(int N, int map[100][100], int floodMap[100][100]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            floodMap[i][j] = map[i][j];
        }
    }
}

void DFS(int N, int floodMap[100][100], int y, int x){
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++){
        
        if(y + dy[k] < 0 || y + dy[k] >= N) continue;
        if(x + dx[k] < 0 || x + dx[k] >= N) continue;
        if(floodMap[y+dy[k]][x+dx[k]] != -1){
            floodMap[y+dy[k]][x+dx[k]] = -1;
            DFS(N, floodMap, y+dy[k], x+dx[k]);
        }

    }
    
}

int findMaximumIslandNum(int N, int map[100][100], int maximumHeight){
    int tempIslandCnt = 0;
    int islandCnt = 0;
    int floodMap[100][100] = { -1, };


    for(int k = 0; k < maximumHeight; k++){
        copyMap(N, map, floodMap);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] <= k) floodMap[i][j] = -1;
            }
        }

        //DFS
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(floodMap[i][j] != -1){
                    floodMap[i][j] = -1;
                    tempIslandCnt++;
                    DFS(N, floodMap, i, j);
                }
            }
        }

        if(tempIslandCnt > islandCnt) islandCnt = tempIslandCnt;
        tempIslandCnt = 0;
    }

    return islandCnt;
}

int main(){
    int N;
    int map[100][100] = { -1, };
    int maximumHeight;
    int islandCnt;
    cin >> N;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> map[i][j];
        }
    }

    maximumHeight = findMaximumHeight(N, map);
    islandCnt = findMaximumIslandNum(N, map, maximumHeight);

    cout << islandCnt;
}