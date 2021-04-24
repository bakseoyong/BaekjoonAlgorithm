#include <iostream>
#include <queue>
using namespace std;

int nodeArray[1001][1001];
int nodeArrive[1001];
queue<int> nodeQueue;

void InitArrive(){
    for(int i = 0; i < 1001; i++){
        nodeArrive[i] = -1;
    }
}

void DFS(int start){
    nodeArrive[start] = 1;

    for(int i = 0; i < 1001; i++){
        if(nodeArray[start][i] == 1 && nodeArrive[i] == -1){
            nodeArrive[i] = 1;
            cout << " " << i;
            DFS(i);
        }
    }
}

void BFS(int start){
    nodeArrive[start] = 1;
    nodeQueue.push(start);
    int front;

    while(!nodeQueue.empty()){
        front = nodeQueue.front();
        nodeQueue.pop();
        for(int i = 0; i < 1001; i++){
            if(nodeArray[front][i] == 1 & nodeArrive[i] == -1){
                nodeArrive[i] = 1;
                cout << " " << i;
                nodeQueue.push(i);
            }
        }
    }
}

int main()
{
    int vertex, node, start;

    int vertex1, vertex2;

    cin >> vertex >> node >> start;

    for(int i = 0; i < 1001; i++){
        nodeArrive[i] = -1;
        for(int j = 0; j < 1001; j++){
            nodeArray[i][j] = -1;
        }
    }

    for(int i = 0; i < node; i++){
        cin >> vertex1 >> vertex2;
        nodeArray[vertex1][vertex2] = nodeArray[vertex2][vertex1] = 1;
    }

    //여기서부터 DFS, BFS 알고리즘 시작
    cout << start;
    DFS(start);
    cout << endl;

    InitArrive();

    cout << start;
    BFS(start);

    return 0;
}