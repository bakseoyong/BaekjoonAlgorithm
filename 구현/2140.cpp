#include <iostream>
using namespace std;

int N;
int map[101][101];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int a(int i, int j){
    int cnt;
    if((i == 1 && j == 1) || (i==1 && j==N-2) || (i == N-2 && j == 1) || (i == N-2 && j == N-2)) 
        cnt = 5;
    else if(i == 1 || i == N-2 || j == 1 || j == N-2) cnt = 3;
    else cnt = 0;

    for(int k = 0; k < 8; k++){
        if(map[i+dx[k]][j+dy[k]] > 0 && map[i+dx[k]][j+dy[k]] != -13)
            cnt--;
    }
    if(cnt == 0) {
        for(int k = 0; k < 8; k++){
            if(map[i+dx[k]][j+dy[k]] > 0 && map[i+dx[k]][j+dy[k]] != -13)
                map[i+dx[k]][j+dy[k]] -= 1;
            }
        return -6; // -6 = *
    }
}

int main(){
    //map[0][0] = '#'; // # = -13
    int anw = 0;
    char tempMap[101][101];
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tempMap[i][j];
            map[i][j] = tempMap[i][j] - 48;
        }
    }

    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            map[i][j] = a(i, j);
            //cout << map[i][j] << " ";
        }
        //cout << endl;
    }

    for(int i = 1; i < N -1; i++){
        for(int j = 1; j < N - 1; j++){
            if(map[i][j] == -6)
                anw++;
        }
    }

    cout << anw;
}