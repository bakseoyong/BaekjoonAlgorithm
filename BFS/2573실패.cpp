#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int mapmap[300][300] = { 0, };
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;
int isIsland[300][300] = { 0,};
int isIslandCnt;


//빙산 갈라짐 확인
void DFS(int y, int x){

    if(isIsland[y][x] == 11)
        return;
    else{
        isIsland[y][x] = 11;
        isIslandCnt--;
        for(int k = 0; k < 4; k++){
            int tempY = y + dy[k];
            int tempX = x + dx[k];
            if(tempY >= 0 && tempY < N && tempX >= 0 && tempX < M && mapmap[tempY][tempX] != 11 && mapmap[tempY][tempX] > 0){
                DFS(tempY, tempX);
            }
        }
    }
    
}

int BFS(){
    int answer = 0;
    bool isEnd = false;
    vector<pair<int, int> > nextYearWillBeMelt;
    bool isWillBeMelt[300][300];

    while(1){ //빙산 갈라질 시 break
        //이번 년도에는 빙산이 갈라져있는가? 아예 없는가?
        if(q.empty()) return 0;
        isIslandCnt = q.size();
        //cout << "Answer : " << answer << " num : " << q.size() << endl;
        //cout << q.front().first << " " << q.front().second << endl;
        DFS(q.front().first, q.front().second);

        if(isIslandCnt != 0) return answer;

        //탐색 + isIsland 초기화
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                isIsland[i][j] = 0;
            }
        }

        int thisYearCnt = q.size();
        //빙산이 한 덩이인 경우 => 내년이 되기 전까지 녹인다.
        for(int i = 0; i < thisYearCnt; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                if(y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < M && mapmap[y + dy[k]][x + dx[k]] == 0 && mapmap[y][x] > 0){
                    if(isWillBeMelt[y][x] == true) continue;

                    mapmap[y][x] -= 1;

                    if(mapmap[y][x] == 0){ //0이 된경우 다른 탐색에 영향을 끼치므로 임시 큐에 저장한 후 년도가 지났을 때 반영해 준다.
                        isWillBeMelt[y][x] = true;
                        nextYearWillBeMelt.push_back(make_pair(y, x));
                        mapmap[y][x] = 1;
                    }
                }
            }
        }

        cout << nextYearWillBeMelt.size() << " << next year will be melt cnt " << endl;
        for(int i = 0;  i < nextYearWillBeMelt.size(); i++){
            mapmap[nextYearWillBeMelt.front().first][nextYearWillBeMelt.front().second] = 0;
            isWillBeMelt[nextYearWillBeMelt.front().first][nextYearWillBeMelt.front().second] = false;
        }

        //아직 안 녹은것들 큐에 넣어준다.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(mapmap[i][j] > 0){
                    q.push(make_pair(i, j));
                }
            }
        }
        

        
        //내년 시작
        answer++;
    }

}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mapmap[i][j];
            if(mapmap[i][j] != 0) q.push(make_pair(i, j)); 
        }
    }

    cout << BFS();
    return 0;
}