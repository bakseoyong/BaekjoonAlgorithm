#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tempCnt = 0;

void DFS(int M, int N, int map[100][100], int y, int x){
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++){
        if(y + dy[k] < 0 || y + dy[k] >= M) continue;
        if(x + dx[k] < 0 || x + dx[k] >= N) continue;
        if(map[y+dy[k]][x+dx[k]] != 1){
            map[y+dy[k]][x+dx[k]] = 1;
            tempCnt++;
            DFS(M, N, map, y+dy[k], x+dx[k]);
        }
    }
}

int main(){
    int M, N, K;
    int firstX[100], firstY[100], secondX[100], secondY[100];
    vector<int> blankArea;

    cin >> M >> N >> K;

    int map[100][100] = { 1, };

    //initMap
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = 0;
        }
    }

    //rectangle
    for(int i =0; i < K; i++){
        cin >> firstX[i] >> firstY[i] >> secondX[i] >> secondY[i];
        for(int j = firstY[i]; j < secondY[i]; j++){
            for(int k = firstX[i]; k < secondX[i]; k++){
                map[j][k] = 1;
            }
        }
    }

    //DFS
    for(int i = 0; i < M; i++){
        for(int j =0; j < N; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                tempCnt++;
                DFS(M, N, map, i, j);
                blankArea.push_back(tempCnt);
                tempCnt = 0;
            }
        }
    }
    
    //sort
    sort(blankArea.begin(), blankArea.end());
    cout << blankArea.size() << endl;
    for(int i = 0; i < blankArea.size(); i++) cout << blankArea[i] << " ";

}