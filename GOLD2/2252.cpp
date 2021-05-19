#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> vec[32001];
int nodeCnt[32001] = { 0, };
queue<int> q;
vector<int> result;

int main(){
    cin >> N >> M;
    
    int a, b;

    for(int i = 0; i < M; i++){
        cin >> a >> b;    
        vec[a].push_back(b);
        nodeCnt[b]++;
    }

    for(int i = 1; i <= N; i++){
        if(nodeCnt[i] == 0){
            q.push(i);
        }
    }


    while(!q.empty()){
        int search = q.front();
        q.pop();
        result.push_back(search);

        for(int i = 0; i < vec[search].size(); i++){
            if(--nodeCnt[vec[search][i]] == 0){
                q.push(vec[search][i]);
            }
        }
    } 

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}