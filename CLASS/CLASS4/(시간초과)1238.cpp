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
    int minIdx;
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

int Dijk(int start, int end){
    for(int i = 1; i <= N; i++){
        dijkstra[i] = cost[start][i]; //INF가 아니니까 0이면 무조건하지
    }

    visited[start] = true;
    for(int i = 0; i < N-1; i++){
        int minIdx = findShortRouteIdx();

        visited[minIdx] = true;
        updateDist(minIdx);
    }

    return dijkstra[end];
}

int main(){
    cin >> N >> M >> X;

    int a, b, c;
    memset(cost, INF, sizeof(cost));

    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
    }

    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        memset(visited, false, sizeof(visited));
        memset(dijkstra, INF, sizeof(dijkstra));
        int A = Dijk(i, X);
        memset(visited, false, sizeof(visited));
        memset(dijkstra, INF, sizeof(dijkstra));
        int B = Dijk(X, i);
        //cout << "i : " << i << " A : " << A << " B : " << B << endl;
        totCost.push_back(A + B);
    }

    sort(totCost.begin(), totCost.end(), greater<int>());

    cout << totCost[0];

}