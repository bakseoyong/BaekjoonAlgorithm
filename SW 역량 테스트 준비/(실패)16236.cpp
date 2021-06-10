#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[20][20] = {0,};
int cnt = 0;
int shkY, shkX;
int shkSize = 2;
int shkSizeUpCnt = 0;
int moveArr[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
int answer = 0;

void A(){
    queue<pair<int , int> > Q;
    int Qsize;
    Q.push(make_pair(shkY, shkX));

    //더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다
    while(cnt){
        vector<pair<int, int> > tempVec;
        int my, mx, y, x;
        Qsize = Q.size();

        //먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다
        for(int i = 0; i < Qsize; i++){
            y = Q.front().first;
            x = Q.front().second;
            Q.pop();
            
            for(int k = 0; k < 4; k++){
                my = shkY + moveArr[k][0];
                mx = shkX + moveArr[k][1];

                if(my >= 0 && my < N && mx >= 0 && mx < N){
                    if(map[my][mx] == 0)
                        Q.push(make_pair(my, mx));
                    else if(map[my][mx] != 9 && map[my][mx] < shkSize){ //거리가 같은 곳에 먹이가 여러개 => y값 x값 비교
                        tempVec.push_back(make_pair(my, mx));
                    }
                }
            }

            if(!tempVec.empty()){
                sort(tempVec.begin(), tempVec.end());
                while(map[tempVec.front().first][tempVec.front().second] >= shkSize){
                    tempVec.pop_back();
                }
                map[shkY][shkX] = 0;
                map[tempVec.front().first][tempVec.front().second] = 9;
                while(!Q.empty()) Q.pop();
                Q.push(make_pair(tempVec.front().first, tempVec.front().second));
                shkY = tempVec.front().first;
                shkX = tempVec.front().second;
                if(++shkSizeUpCnt == shkSize){
                    shkSizeUpCnt = 0;
                    shkSize++;
                }
            }
        }
        
        answer++;
    }
}


/*
map[shkY][shkX] = 0;
                        map[my][mx] = 9;
                        while(!Q.empty()) Q.pop();
                        Q.push(make_pair(my, mx));
                        shkY = my; 
                        shkX = mx;
                        if(++shkSizeUpCnt == shkSize){
                            shkSizeUpCnt = 0;
                            shkSize++;
                        }
*/
int main(){
    cin >> N;

    int ky = 0;
    if(++ky == 1) cout << "hello " << endl;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 9) cnt++;
            if(map[i][j] == 9){
                shkX = j;
                shkY = i;
            }
        }
    }

    A();
}