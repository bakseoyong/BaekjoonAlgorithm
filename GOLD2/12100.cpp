#include <iostream>
using namespace std;

int N;
int map[21][21];
int maxValue = 0;

void recursive(int cnt){
    if(cnt == 5){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                maxValue = maxValue > map[i][j] ? maxValue : map[i][j]; 
            }
        }
        return;
    }else{
        //상
        int tempY = -1;
        int tempIndex = 0;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(map[x][y] != 0 && tempY == -1){ //탐지를 시작한다.
                    tempY = map[x][y];
                }
                else if(map[x][y] == 0 && tempY != -1){ // 탐지하는 중인데 0이면 그냥 continue;
                    continue;
                }else if(map[x][y] != 0 && tempY == map[x][y]){ //탐지하는 중인데 탐지된 블럭의 숫자가 나와 같다면 값2배, 이쪽은 0으로
                    map[x][tempIndex] *= 2;
                    //탐지가 끝났으니 tempY 초기화
                    tempY = -1;
                    tempIndex++;
                }else if(map[x][y] == 0 && tempY == -1){ // 탐지도 안하고 있는데 0이면
                    continue;
                }else if(map[x][y] != 0 && tempY != map[x][y] && tempY != -1){ //탐지를 하고 있는데 나와 다른 수를 만난다면. (tempY 는 -1이 아님) 
                    
                }
            }
        }
        //하
        //좌
        //우
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j]; 
        }
    }

    //이게 상하좌우 5번이니까 4의 5승하면 1024번이니까 시간초과 날 일은 없을 것 같다.
    recursive(0);
}