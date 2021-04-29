#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int dist[1001];
vector<pair<int, int> > routeQueue[1001];

void initDistance(int N){
    for(int i = 0; i <= N; i++){
        dist[i] = INF;
    }
}

void Dijkstra(int start){
    int destCity, destCost;
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        destCity = pq.top().first;
        destCost = -pq.top().second;
        pq.pop();

        //기존에 저장된 거리값이 더 짧다면
        if(destCost < dist[destCity]) continue;
        else
        {
            for(int i = 0; i < routeQueue[destCity].size(); i++){
                if(routeQueue[destCity][i].second + destCost < dist[routeQueue[destCity][i].first]){
                    dist[routeQueue[destCity][i].first] = routeQueue[destCity][i].second + destCost;
                    pq.push(make_pair(routeQueue[destCity][i].first , -(routeQueue[destCity][i].second + destCost) ));
                }
            }
        }

    }
}

int main(){
    int N, M;
    int a, b, c;
    int start, end;

    cin >> N;
    cin >> M;

    initDistance(N);

    //출발, 도착, 비용 입력
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        routeQueue[a].push_back(make_pair(b, c));
    }

    //출발지, 도착지
    cin >> start >> end;

    //다익스트라
    Dijkstra(start);


    cout << dist[end];
}
