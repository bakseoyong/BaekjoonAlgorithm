#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int> > edge[20001];
int dest[20001];

void initDistance(int V){
    for(int i = 0; i <= V; i++){
        dest[i] = INF;
    }
}

void Dijkstra(int K){
    priority_queue<pair<int, int> > pq;
    int destCity, destCost;

    dest[K] = 0;
    pq.push(make_pair(K, 0));

    while(!pq.empty()){
        destCity = pq.top().first;
        destCost = -pq.top().second;
        pq.pop();

        if(destCost > dest[destCity]) continue;
        else
        {
            for(int i = 0; i < edge[destCity].size(); i++){
                int tempCost = destCost + edge[destCity][i].second;
                if(tempCost < dest[edge[destCity][i].first]){
                    dest[edge[destCity][i].first] = tempCost;
                    pq.push(make_pair(edge[destCity][i].first, -tempCost));
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E, K;
    int a, b, c;
    cin >> V >> E >> K;

    initDistance(V);
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
    }

    Dijkstra(K);

    for(int j = 1; j <= V; j++){
        if(dest[j] == INF) cout << "INF" << endl;
        else cout << dest[j] << endl;
    }
}