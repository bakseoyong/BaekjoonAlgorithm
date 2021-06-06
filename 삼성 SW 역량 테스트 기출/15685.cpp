#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N, x, y, d, g;
int generation[1024] = { 0, };
int dy[4] = {0, 0, 1, 1};
int dx[4] = {0, 1, 1, 0};
bool visited[101][101];
int answer = 0;

void calGen(){ //0세대 1개, 1세대 2개, 2세대 4개, 3세대 8개
    memset(generation, 0, sizeof(generation));
    generation[0] = d;

    if(g == 0) return;

    for(int k = 1; k <= g; k++){
        int calGenNum = pow(2, k);
        int j = 1;

        for(int i = calGenNum / 2; i < calGenNum; i++){
            generation[i] = (generation[i-j] + 1) % 4;
            j += 2;
        }
    }

    return;
}

void makeDragonCurve(){
    visited[y][x] = true;    

    int genNum = pow(2, g);

    for(int i = 0; i < genNum ; i++){
        if(generation[i] == 0){
            x += 1;
            //cout << "0 index : " << i << " y value : " << y << " x value : " << x << endl;
        }else if(generation[i] == 1){
            y -= 1;
            //cout << "1 index : " << i << " y value : " << y << " x value : " << x << endl;
        }else if(generation[i] == 2){
            x -= 1;
            //cout << "2 index : " << i << " y value : " << y << " x value : " << x << endl;
        }else{
            y += 1;
            //cout << "3 index : " << i << " y value : " << y << " x value : " << x << endl;
        }
        visited[y][x] = true;
    }

}

int main(){
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> x >> y >> d >> g;
        calGen();
        
        makeDragonCurve();
    }

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            int temp = 0;
            for(int k = 0; k < 4; k++){
                if(visited[i+dy[k]][j+dx[k]] && i+dy[k] >= 0 && i+dy[k] < 101 && j+dx[k] >= 0 && j+dx[k] < 101) temp++;
            }
            if(temp == 4)
                answer++;
        }
    }

    cout << answer;
}
