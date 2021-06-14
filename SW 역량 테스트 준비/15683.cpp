#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int mvArr[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};
int map[8][8] = {0, };
vector<pair<int, int > > V, wallV;
int answer = 0;

void B(int y, int x, int rotCnt, int cctv){
    int cnt = 1;
    int tempRotCnt = rotCnt;

    if(cctv >= 3) cnt++; //3일떄는 2번시행, 4일때 3번시행, 5일때 4번시행

    while(cnt <= cctv){
        int mvY = y;
        int mvX = x;

        while(1){
            mvY += mvArr[tempRotCnt][0];
            mvX += mvArr[tempRotCnt][1];
            if(mvY < 0 || mvY >= N || mvX < 0 || mvX >= M) break;
            if(map[mvY][mvX] == 6) break;
            if(map[mvY][mvX] > 0 && map[mvY][mvX] <= 5) continue;
            map[mvY][mvX] = 7; // #
        }

        cnt++;
        tempRotCnt = (tempRotCnt + 1) % 4;
        if(cctv == 2) tempRotCnt++; //2일경우 반대편으로 탐색해야 하므로

        //cout << " temp Rot : " << tempRotCnt << endl;
    }
}

void A(int vecIdx){
    if(vecIdx == V.size()) {
        int tmpAns = 0;
        //개수확인
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0) tmpAns++;
            }
        }
        answer = min(tmpAns, answer);
        return;
    }

    int tmpMap[8][8]; //재귀 할 때마다 가지고 있는 map
    memcpy(tmpMap, map, sizeof(map));

    int y = V[vecIdx].first;
    int x = V[vecIdx].second;

    // B(y, x, 0, map[y][x]);

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    for(int k = 0; k < 4; k++){
        B(y, x, k, map[y][x]);
        A(vecIdx + 1);
        memcpy(map, tmpMap, sizeof(tmpMap));
    }
}

int main(){
    cin >> N >> M;

    answer = N * M;

    for(int i =0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6){
                V.push_back(make_pair(i, j));
            }
            else if(map[i][j] == 6) {
                wallV.push_back(make_pair(i, j)); 
            }
        };
    }

    A(0);

    cout << answer;
}