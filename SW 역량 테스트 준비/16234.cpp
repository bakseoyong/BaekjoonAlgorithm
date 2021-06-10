#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int N, L, R;
int map[50][50] = { 0, };
int mvArr[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
int borderMap[50][50] = {0,};
int openBorder = 0;
queue<tuple<int, int, int> > Q;
int sumArr[3000] = { 0, };
int unionSize[3000] = { 0, };


void A(int y, int x, int cnt){
 
    Q.push(make_tuple(y, x, cnt));
    borderMap[y][x] = cnt;
    sumArr[cnt] += map[y][x];
    unionSize[cnt]++;

    while(!Q.empty()){
        int y = get<0>(Q.front());
        int x = get<1>(Q.front());
        int c = get<2>(Q.front());
        Q.pop();

        int my, mx;
        for(int k = 0; k < 4; k++){
            my = y + mvArr[k][0];
            mx = x + mvArr[k][1];

            
            if(my >= 0 && my < N && mx >= 0 && mx < N && !borderMap[my][mx]){
                int absValue = abs(map[y][x] - map[my][mx]);
                if(absValue >= L && absValue <= R){
                    openBorder++;
                    Q.push(make_tuple(my, mx, c));
                    borderMap[my][mx] = c;
                    sumArr[c] += map[my][mx];
                    unionSize[c]++;
                }
            }
        }
    }
}

void B(){
    
    //if(unionSize[asso] == 0) return;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = sumArr[borderMap[i][j]] / unionSize[borderMap[i][j]];
        }
    }
}

int main(){
    int answer = 0;

    cin >> N >> L >> R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    while(1){
        int cnt = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(borderMap[i][j] == 0){
                    A(i, j, cnt++);
                    //cout << i << " " << j << " " << cnt << endl;
                }
            }
        }
        
        if(openBorder == 0) break;

        B();

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }

        memset(sumArr, 0, sizeof(sumArr));
        memset(unionSize, 0, sizeof(unionSize));
        memset(borderMap, 0, sizeof(borderMap));
        openBorder = 0;
        answer++;
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << borderMap[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << "+===========================" << endl;
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << answer;
}