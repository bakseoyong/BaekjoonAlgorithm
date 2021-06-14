#include <iostream>
#include <cstring>
#define INF 999999
using namespace std;

int N;
int map[200][200] = { 0, };
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int cost[15626][15626];
int dijkstra[15626] = { 0, };
bool visited[15626];

void MakeDijkstraGraph(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 4; k++){
                int ty = i + dy[k];
                int tx = j + dx[k];

                if(ty >= 0 && ty < N && tx >= 0 && tx < N){
                    cost[i * N + j][ty * N + tx] = map[ty][tx]; //0,0 => 1,0 ==> 0에서 4까지 이동하는데 드는 비용 3
                }
            }
        }
    }
}

int FindShortestCostIndex(){
    int shortestCostIndex, shortestCost = INF;

    for(int i = 0; i < N * N; i++){ 
        if(visited[i]) continue;

        if(shortestCost > dijkstra[i] && !visited[i]){
            shortestCostIndex = i;
            shortestCost = dijkstra[i];
        }
    }
    
    return shortestCostIndex;
}

void UpdateShortestCost(int fixedShortestCost){
    for(int i = 0; i < N * N; i++){
        if(!visited[i]){
            if(dijkstra[i] > cost[fixedShortestCost][i] + dijkstra[fixedShortestCost]){
                dijkstra[i] = cost[fixedShortestCost][i] + dijkstra[fixedShortestCost];
            }
        }
    }
}

void DetectionShortestCost(){
    for(int i = 0; i < N * N; i++){
        dijkstra[i] = cost[0][i];
    }

    visited[0] = true;

    for(int i = 0; i < N * N - 1; i++){
        int fixedShortestCost = FindShortestCostIndex();

        UpdateShortestCost(fixedShortestCost);
        visited[fixedShortestCost] = true;
    }
}


int main(){
    int cnt = 1;

    cin >> N;

    while(N != 0){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }

        memset(cost, INF, sizeof(cost));
        MakeDijkstraGraph();

        memset(dijkstra, INF, sizeof(dijkstra));
        memset(visited, false, sizeof(visited));
        DetectionShortestCost();

        // for(int i = 0; i < N * N; i++){
        //     for(int j = 0; j < N * N; j++){
        //         cout << cost[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // for(int i = 0; i < N * N; i++){
        //     cout << dijkstra[i] << " ";
        // }
        // cout << endl;

        cout << "Problem " << cnt++ << ": " << dijkstra[N * N - 1] + map[0][0] << endl;

        cin >> N;
    }    
}