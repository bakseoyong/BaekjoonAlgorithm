#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 999999
using namespace std;

int N, M, X;
int cost[1001][1001] = { 0, };
vector<int> totCost;
int dijkstra[1001] = {0,};
bool visited[1001];

int findShortRouteIdx(){
    int minIdx = -1;
    int minDist = INF;

    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;

        if(dijkstra[i] < minDist){
            minDist = dijkstra[i];
            minIdx = i;
        }
    }

    //cout << "minIdx : " << minIdx << endl;
    return minIdx;
}

void updateDist(int minIdx){
    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;

        if(dijkstra[minIdx] + cost[minIdx][i] < dijkstra[i]){
            //cout << "dijkstra[minIdx] : " << dijkstra[minIdx] << " cost[minidx][i]  : " << cost[minIdx][i] << endl;
            dijkstra[i] = dijkstra[minIdx] + cost[minIdx][i];
            //cout << " i : " << i << " dijkstra[i] : " << dijkstra[i] << endl;
        }
    }
}

void Dijk(int start){
    for(int i = 1; i <= N; i++){
        dijkstra[i] = cost[start][i]; //INF가 아니니까 0이면 무조건하지
    }

    visited[start] = true;
    for(int i = 0; i < N-1; i++){
        int minIdx = findShortRouteIdx();

        visited[minIdx] = true;
        updateDist(minIdx);
    }
}

int main(){
    int rvsCost[1001][1001] = { 0, };
    int a, b, c;

    cin >> N >> M >> X;

    memset(cost, INF, sizeof(cost));
    memset(rvsCost, INF, sizeof(rvsCost));

    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
        rvsCost[b][a] = c;
    }

    Dijk(X);
    int arriveDijk[1001];
    memcpy(arriveDijk, dijkstra, sizeof(dijkstra));

    memset(dijkstra, INF, sizeof(dijkstra));
    memset(visited, false, sizeof(visited));
    memcpy(cost, rvsCost, sizeof(rvsCost));

    //cout << "=================" << endl;
    Dijk(X);

    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        totCost.push_back(arriveDijk[i] + dijkstra[i]);
    }

    sort(totCost.begin(), totCost.end(), greater<int>());

    cout << totCost[0];

}