#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> node[1001];
bool visited[1001];
int answer = 0;

void BFS(int i){
    queue<int> q;

    q.push(i);
    visited[i] = true;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        for(int j = 0; j < node[vertex].size(); j++){
            if(visited[node[vertex][j]] == false){
                q.push(node[vertex][j]);
                visited[node[vertex][j]] = true;
            }
        }
    }

    answer++;
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i]) BFS(i);
    }

    cout << answer;
}