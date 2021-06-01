#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> node[101];
int answerNum = 999999;
int answerPerson = 999999;


void BFS(int i){
    queue<int> q;
    q.push(i);
    int cnt = 0;
    bool visited[101];
    int visitedNum[101] = { 0, };
    int sum = 0;

    for(int j = 1; j <= N; j++)
        visited[j] = false;
    
    visited[i] = true;

    while(!q.empty()){
        int vertex = q.front();
        cnt = visitedNum[vertex];
        q.pop();
        for(int j = 0; j < node[vertex].size(); j++){
            if(visited[node[vertex][j]] == false){
                visitedNum[node[vertex][j]] = cnt + 1;
                visited[node[vertex][j]] = true;
                q.push(node[vertex][j]);
            }
        }
    }

    for(int j = 1; j <= N; j++){
        sum += visitedNum[j];
    }

    if(sum < answerNum){
        answerNum = sum;
        answerPerson = i;
    }else if(sum == answerNum){
        answerPerson = i > answerPerson ? answerPerson : i;
    }
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
        BFS(i);
    }
    
    cout << answerPerson;
}