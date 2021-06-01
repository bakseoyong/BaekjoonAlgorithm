#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//visited 2차원 배열 => 재확인 가능
int V, E;
vector<int> edge[20001];
int isOneTwo[20001] = { 0, };

bool BFS(int i){
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int fr = q.front();
        q.pop();

        for(int i = 0; i < edge[fr].size(); i++){
            //이미 집합의 값이 정해진 경우 => 검증을 위해 상대방과 집합이 다른곳에 속하고 있는지 확인한다.
            if(isOneTwo[edge[fr][i]] != 0){
                if(isOneTwo[fr] == isOneTwo[edge[fr][i]]){
                    return false;
                }
            }
            //해당 정점에 처음들어온 경우
            else{
                isOneTwo[fr] == 1 ? isOneTwo[edge[fr][i]] = 2 : isOneTwo[edge[fr][i]] = 1;
                q.push(edge[fr][i]);
            }
        }
    }
    
    return true;
}

int main(){
    int K;

    cin >> K;

    while(K--){
        bool fail = false;
        int a, b;

        cin >> V >> E;

        for(int i = 0; i < E; i++){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        isOneTwo[1] = 1;
        for(int i = 1; i <= V; i++){
            if(BFS(i) == false){
                fail = true;
                break; //for문 break
            }
        }

        //방문 , vector, isOneTwo 초기화
        for(int i = 1; i <= V; i++){
            isOneTwo[i] = 0;

            while(!edge[i].empty())
                edge[i].pop_back();

        }


        if(fail == true){
            cout << "NO" << endl;
            continue; //다음 케이스로
        }else{
            cout << "YES" << endl;
            continue;
        }

    }
}