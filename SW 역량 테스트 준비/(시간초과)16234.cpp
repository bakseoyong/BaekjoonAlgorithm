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
bool visited[50][50];
int borderMap[50][50] = {0,};
int openBorder = 0;

void A(int y, int x, int cnt){
    queue<tuple<int, int, int> > Q;

    Q.push(make_tuple(y, x, cnt));
    visited[y][x] = true;
    borderMap[y][x] = cnt;

    while(!Q.empty()){
        int y = get<0>(Q.front());
        int x = get<1>(Q.front());
        int c = get<2>(Q.front());
        Q.pop();

        int my, mx;
        for(int k = 0; k < 4; k++){
            my = y + mvArr[k][0];
            mx = x + mvArr[k][1];

            if(my >= 0 && my < N && mx >= 0 && mx < N){
                int absValue = abs(map[y][x] - map[my][mx]);
                if(absValue >= L && absValue <= R && !visited[my][mx]){
                    openBorder++;
                    Q.push(make_tuple(my, mx, c));
                    borderMap[my][mx] = c;
                    visited[my][mx] = true;
                }
            }
        }
    }
}

void B(int asso){
    int sum = 0;
    int assoCnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(borderMap[i][j] == asso){
                sum += map[i][j];
                assoCnt++;
            }
        }
    }

    sum /= assoCnt;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(borderMap[i][j] == asso){
                map[i][j] = sum;
            }
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
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visited[i][j] == false){
                    A(i, j, cnt++);
                    //cout << i << " " << j << " " << cnt << endl;
                }
            }
        }
        
        if(openBorder == 0) break;

        for(int i = 0; i < cnt; i++){
            B(i);
        }

        memset(borderMap, 0, sizeof(borderMap));
        memset(visited, false, sizeof(visited));
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