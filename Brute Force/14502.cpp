#include <iostream>
#include <queue>
using namespace std;

int row, col;
queue<pair<int,int> > virusLocation;

int verticalMove[4] = {1, 0, -1, 0};
int horizontalMove[4] = {0, 1, 0, -1};

int finalSecureCnt = 0;

void initMap(int map[9][9]){
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col; j++){
            map[i][j] = -1;
        }
    }
}

void copyMap(int map[9][9], int virusSpreadMap[9][9]){
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col; j++){
            virusSpreadMap[i][j] = map[i][j];
        }
    }
}

void detectInitVirus(int map[9][9]){
    for(int y = 0; y < row; y++){
        for(int x = 0; x < col; x++){
            if(map[y][x] == 2){
                virusLocation.push(make_pair(y, x));
            }
        }
    }
}

int calculateSecureArea(int virusSpreadMap[9][9]){
    int secureCnt = 0;

    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col; j++){
            if(virusSpreadMap[i][j] == 0){
                secureCnt++;
            }
        }
    }

    return secureCnt;
}

int spreadVirus(int map[9][9]){ // BFS
    int virusSpreadMap[9][9];
    copyMap(map, virusSpreadMap);

    int virusX, virusY;
    int secureCnt = 0;

    while(!virusLocation.empty()){
        virusX = virusLocation.front().second;
        virusY = virusLocation.front().first;
        virusLocation.pop();


        for(int k = 0 ; k < 4; k++){
            //좌표값, 인덱스 값 구별 않고 작성한 것을 인지하지 못해 많은 시간 소모.
            if(virusY + verticalMove[k] < 0 || virusSpreadMap[virusY+ verticalMove[k]][virusX] == 1 || virusY + verticalMove[k] >= row){
                continue;
            }
            if(virusX + horizontalMove[k] < 0 || virusSpreadMap[virusY][virusX + horizontalMove[k]] == 1 || virusX + horizontalMove[k] >= col){
                continue;
            }
            if(virusSpreadMap[virusY + verticalMove[k]][virusX + horizontalMove[k]] == 0){
                virusSpreadMap[virusY + verticalMove[k]][virusX + horizontalMove[k]] = 2;
                virusLocation.push(make_pair(virusY + verticalMove[k], virusX + horizontalMove[k]));
            }
        }
    }

    secureCnt = calculateSecureArea(virusSpreadMap);
    return secureCnt;
}

int bruteForce(int map[9][9], int cnt){
    int tempCnt;
    int isVisited[9][9];

    if(cnt == 3){
        
        detectInitVirus(map);
        tempCnt = spreadVirus(map);
        if(tempCnt > finalSecureCnt) finalSecureCnt = tempCnt;

        return 0;
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                bruteForce(map, cnt+1);
                map[i][j] = 0;
            }
        }
    }
    return 0;
}

int main(){
    int map[9][9];
    int secureCnt = 0;

    initMap(map);

    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    bruteForce(map, 0);

    cout << finalSecureCnt;
}