#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<string> mapString;
char map[12][6];
bool visited[12][6];
vector<int > disappearIndex[6];
int puyoCnt = 0;
int answer = 0;
int concurrentCnt = 0;
bool firstTime = true;
queue<pair<int, int> > tempQueue;

void DFS(int y, int x, char color){
    for(int k = 0; k < 4; k++){
        if(map[y+dy[k]][x+dx[k]] != color || y+dy[k] > 11 || y+dy[k] < 0 ||
        x + dx[k] > 5 || x + dx[k] < 0 || visited[y+dy[k]][x+dx[k]] == true) 
            continue;
        else{
            puyoCnt++;
            tempQueue.push(make_pair(y+dy[k], x+dx[k]));
            visited[y+dy[k]][x+dx[k]] = true;
            DFS(y+dy[k], x+dx[k], color);
        }
    }
}

vector<string> erase(vector<string> input){

    for(long unsigned int j = 0; j < input.size(); j++){
        for(long unsigned int i = 0; i < disappearIndex[j].size(); i++){
            input[j].erase(disappearIndex[j][i], 1); //disappearIndex에 저장된 y인덱스 값들을 erase해준다.
        }

        while(input[j].size() != 12){
            input[j] = '.' + input[j];
        }
    }

    return input;
}

void initVisited(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(visited[i][j] == true)
                visited[i][j] = false;
        }
    }
}


int main(){
    char c;
    for(int i = 0; i < 6; i++){
        mapString.push_back("");
    }
    
    //map[0] = ..........RR; - DFS확인용
    //mapString[0] = ..........RR; - 뿌요 내리기용
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> c;
            map[i][j] = c;
            mapString[j] += c;
        }
    }
    
    //터질 수 있는 뿌요가 없을 때까지 (concurrentCnt) || 첫 시행인 경우
    while(concurrentCnt != 0 || firstTime == true){
        concurrentCnt = 0; // 들어왔으니까 초기화
        firstTime = false; // 스파게티코드

        for(int i = 11; i >= 0; i--){
            for(int j = 0; j < 6; j++){
                if(map[i][j] != '.' && visited[i][j] == false){
                    //맨 처음 탐색 좌표 추가 + visited 추가 + puyoCnt 추가
                    tempQueue.push(make_pair(i, j));
                    visited[i][j] = true;
                    puyoCnt++;

                    //4연속 이상인지 확인
                    DFS(i, j, map[i][j]);

                    //4연속 이상이라면, 해당 연쇄 카운트를 1 올린다.
                    if(puyoCnt >= 4){
                        concurrentCnt++;
                        while(!tempQueue.empty()){
                            int idxX = tempQueue.front().second;
                            int idxY = tempQueue.front().first;
                            tempQueue.pop();

                            disappearIndex[idxX].push_back(idxY);//사라지는 x,y 저장
                        }
                    }else{ //4연속 미만이라면, tempQueue그냥 초기화
                        while(!tempQueue.empty()) tempQueue.pop();
                    }
                    //카운트 초기화
                    puyoCnt = 0;   
                }
            }
        }

        //연쇄 카운트가 1 이상일시, mapString을 통해 연속된 뿌요를 없애주고, 위에 위치한 뿌요를 내려준다.
        mapString = erase(mapString);

        //erase에서 지운걸 실제 map에 반영
        for(int k = 0; k < 6; k++){
            for(int q = 0; q < 12; q++){
                map[q][k] = mapString[k][q];
            }
        }


        //정답을 1 올려준다.
        if(concurrentCnt != 0)
            answer++;

        //수정된 내용들을 초기화한다.
        initVisited();
        for(int t = 0; t < 6; t++){
            while(!disappearIndex[t].empty()) 
                disappearIndex[t].pop_back();
        }
    }

    cout << answer;

}