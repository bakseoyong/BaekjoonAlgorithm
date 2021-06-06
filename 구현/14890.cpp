#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int N, L;
int map[100][100];
int currentHeight;
int answer = 0;
bool isInstalled[100];

//가로 , 통과할 수 없는 조건들을 나열시켜서 뺴내가야 한다.
int a(int row){
    currentHeight = map[row][0];
    memset(isInstalled, false, sizeof(isInstalled));

    for(int i = 1; i < N; i++){
        int heightDiff = abs(map[row][i] - currentHeight);
        if(heightDiff >= 2) return 0;
        else if(heightDiff == 1){ //높이가 1차이 나는경우 = > 경사로 = > 경사로를 설치할 수 있는 길이가 확보되어 있는지 확인한다.
            //탐색이 더 높은지, currentHeight가 더 높은지
            if(map[row][i] < currentHeight){ //전 블럭이 더 높다.
                for(int j = i; j < i + L; j++){
                    if(map[row][j] == map[row][i] && isInstalled[j] == false){ //높이들이 서로 같으며, 이전에 설치물이 없다면
                        isInstalled[j] = true;
                    }else{
                        return 0;
                    }
                }
            }else{ //지금이 더 높다
                for(int j = i - 1; j > i-1-L; j--){ //i가 4면 j는 3이고 L이 2라면  3 2 가 경사로 설치
                    if(j < 0 || isInstalled[j] == true) return 0;
                    else isInstalled[j] = true;
                }
            }
            currentHeight = map[row][i];
        }
        else continue; //높이가 같은 경우
    }

    //끝까지 간 경우
    //cout << "row : " << row << endl;
    return 1;
}

//세로
int b(int col){
    currentHeight = map[0][col];
    memset(isInstalled, false, sizeof(isInstalled));

    for(int i = 1; i < N; i++){
        int heightDiff = abs(map[i][col] - currentHeight);
        if(heightDiff >= 2) return 0;
        else if(heightDiff == 1){ //높이가 1차이 나는경우 = > 경사로 = > 경사로를 설치할 수 있는 길이가 확보되어 있는지 확인한다.
            //탐색이 더 높은지, currentHeight가 더 높은지
            if(map[i][col] < currentHeight){ //전 블럭이 더 높다.
                for(int j = i; j < i + L; j++){
                    if(map[j][col] == map[i][col] && isInstalled[j] == false){ //높이들이 서로 같으며, 이전에 설치물이 없다면
                        isInstalled[j] = true;
                    }else{
                        return 0;
                    }
                }
            }else{ //지금이 더 높다
                for(int j = i - 1; j > i-1-L; j--){ //i가 4면 j는 3이고 L이 2라면  3 2 가 경사로 설치
                    if(j < 0 || isInstalled[j] == true) return 0;
                    else isInstalled[j] = true;
                }
            }
            currentHeight = map[i][col];
        }
        else continue; //높이가 같은 경우
    }

    //끝까지 간 경우
    //cout << "col : " << col << endl;
    return 1;
}

int main(){
    cin >> N >> L;

    for(int i = 0; i <N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        answer += a(i);
        answer += b(i);
    }

    cout << answer;
}