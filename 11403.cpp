#include <iostream>
#include <queue>
using namespace std;


void findRoute(int node[100][100], int N){

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(node[i][k] + node[k][j] == 2){
                    node[i][j] = 1;
                }
            }
        }
    }
}

int main(){
    int N;
    int node[100][100];
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> node[i][j];
        }
    }

    findRoute(node, N);

    for(int i = 0; i < N; i++){
        cout << node[i][0];
        for(int j = 1; j < N; j++){
            cout << " " << node[i][j];
        }
        cout << endl;
    }
}