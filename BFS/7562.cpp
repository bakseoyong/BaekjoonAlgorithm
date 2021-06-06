#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, L;
bool visited[300][300];
queue<pair<int, int> > q;
int destY, destX;
int nightMove[8][2] = {
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}
};

int find(){
    int day = 0;

    while(1){
        
        int nowY;
        int nowX;
        int dayQueueSize = q.size();

        for(int i = 0; i < dayQueueSize; i++){
            nowY = q.front().first;
            nowX = q.front().second;
            q.pop();

            if(nowY == destY && nowX == destX){
                return day;
            }

            for(int k = 0; k < 8; k++){
                int my = nowY + nightMove[k][0];
                int mx = nowX + nightMove[k][1];

                if(my >= 0 && my < L && mx >= 0 && mx < L && visited[my][mx] == false){
                    visited[my][mx] = true;
                    q.push(make_pair(my, mx));
                }
            }
        }
        day++;
    }

}


int main(){
    cin >> T;

    while(T--){
        cin >> L;
        int a, b;
        cin >> a >> b;
        q.push(make_pair(a, b));
        visited[a][b] = true;
        cin >> destY >> destX;

        cout << find() << endl;

        memset(visited, false, sizeof(visited));
        while(!q.empty()) q.pop();
    }
}