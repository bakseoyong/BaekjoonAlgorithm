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

void DFS(int y, int x, char color){
    for(int k = 0; k < 4; k++){
        if(map[y+dy[k]][x+dx[k]] != color || y+dy[k] > 11 || y+dy[k] < 0 ||
        x + dx[k] > 5 || x + dx[k] < 0 || visited[y+dy[k]][x+dx[k]] == true) 
            continue;
        else{
            puyoCnt++;
            disappearIndex[x+dx[k]].push_back(y+dy[k]); //사라지는 x,y 저장
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
    
    for(int i = 11; i >= 0; i--){
        for(int j = 0; j < 6; j++){

            if(map[i][j] != '.'){
                //4연속 이상인지 확인
                DFS(i, j, map[i][j]);
                //4연속 이상이라면, disIndex에 저장된 y인덱스값을 확인하여 위에 위치한 뿌요를 내리는 작업 수행
                if(puyoCnt >= 4){
                    //벡터로 저장된 disIndex를 빼내면서 mapString을 erase.
                    mapString = erase(mapString);
                

                    //erase에서 지운걸 실제 map에 반영
                    for(int k = 0; k < 6; k++){
                        for(int q = 0; q < 12; q++){
                            map[q][k] = mapString[k][q];
                        }
                    }

                    // cout << "================" << endl;
                    // for(int k = 0; k < 12; k++){
                    //     for(int q =0 ; q < 6; q++){
                    //         cout << map[k][q];
                    //     }
                    //     cout << endl;
                    // }

                    //정답에 1 추가
                    answer++;

                    //탐색된 후, 뿌요가 내려와서 탐색되지 못하는 경우가 생기므로 탐색하는 변수도 초기화 (시간초과 우려)
                    i = 11;
                    j = 0;
                }
                
            }

            //해당좌표에서의 작업이 끝났으므로 초기화
            puyoCnt = 0;
            initVisited();
            for(int t = 0; t < 6; t++){
                while(!disappearIndex[t].empty()) 
                    disappearIndex[t].pop_back();
            }
        }
    }

    cout << answer;

}