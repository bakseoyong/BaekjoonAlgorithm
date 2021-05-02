#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50] = { 0, };
deque<pair<int, int> > dq;
deque<pair<int, int> > dqCh;
int visited[13] = { 0, };
int minChickenDist = 987654321;

void recursive(int idx, int cnt){

    if(cnt == M){
        int tempTotal = 0;

        for(int i = 0; i < dq.size(); i++){
            int houseY = dq[i].first;
            int houseX = dq[i].second;
            int tempLength = 987654321;

            for(int j = 0; j < dqCh.size(); j++){
                if(visited[j]){
                    int chiY = dqCh[j].first;
                    int chiX = dqCh[j].second;

                    tempLength = min(tempLength, abs(chiY-houseY) + abs(chiX - houseX));
                }
            }
            tempTotal += tempLength;
            //cout << "houseY" << houseY << " houseX " << houseX << "tempLength " << tempLength << endl;
        }
        minChickenDist = min(minChickenDist, tempTotal);
        return;
    }

    
    //segment fault 방지
    if(idx == dqCh.size()) return;

    visited[idx] = 1;
    recursive(idx + 1, cnt + 1);

    visited[idx] = 0;
    recursive(idx + 1, cnt);
}


int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                dq.push_back(make_pair(i, j));
            else if(map[i][j] == 2)
                dqCh.push_back(make_pair(i, j));
        }
    }

    recursive(0, 0);
    
    cout << minChickenDist;
}