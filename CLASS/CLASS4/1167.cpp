#include <iostream>
#include <vector>
using namespace std;

int V;
vector<pair<int, int> > cost[100001];
int dijkCost[100001];
bool visited[100001];

int findLongRouteIndex(int idx){ //idx 넣는게 맞는지 확인
    int longIdx, longCost = 0;

    for(int i = 0; i < cost[idx].size(); i++){
        if(longCost < dijkCost[cost[idx][i].first] && !visited[cost[idx][i].first]){
            longCost = dijkCost[cost[idx][i].first];
            longIdx = i;
        }
    }

    return longIdx;
}

void Dijk(int idx){
    for(int i = 0; i < cost[idx].size(); i++){
        dijkCost[cost[idx][i].first] = cost[idx][i].second;
    }

    visited[idx] = true;

    for(int i = 0; i < V -1; i++){ //모든 정점에 대해 가장 긴 거리를 탐색해야 하므로.
        int longRutIdx = findLongRouteIndex(idx);
        visited[cost[idx][longRutIdx].first] = true;


    }
}

int main(){
    cin >> V;
    
    int a;

    for(int i = 0; i < V; i++){
        cin >> a;
        int b, c;
        cin >> b;
        while(b != -1){
            cin >> c;
            cost[a].push_back(make_pair(b, c));
            cin >> b;
        }
    }

    for(int i = 0; i < V; i++){
        Dijk(i);
    }
}