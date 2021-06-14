#include <iostream>
#include <queue>
using namespace std;

int H, W;
int map[500][500];
bool start = false;
int totalWeight = 0;

void w(){
    for(int i = 0; i < H; i++){
        int cnt = 0; //높이가 한칸씩 올라갈때마다 카운트를 초기화
        start = false;

        for(int j = 0; j < W; j++){

            if(map[i][j] == 1 && start == false){ //맨 첫 벽을 발견하면 고이는 빗물을 측정할 첫번째 벽으로 설정
                // cout << i << " " << j << endl;
                start = true;
                continue;
            }
            else if(map[i][j] == 1 && start == true){ //반대편 벽을 만났으면, 벽과 벽사이에 빗물을 계산한다. 그리고 만난벽은 다시 첫번째 벽이 된다.
                totalWeight += cnt;
                cnt = 0;
            }
            else if(map[i][j] == 0 && start == true){ //빗물이 고일 벽이 왼쪽에는 있다는 뜻.
                cnt++;
            }
        }
    }
}

int main(){
    queue<pair<int, int> > q;
    int index, height;

    cin >> H >> W;

    for(int i = 0; i < W; i++){
        cin >> height;
        for(int j = 0; j < height; j++){
            map[j][i] = 1;
        }
    }

    // for(int i = 0; i < H; i++){
    //     for(int j = 0; j < W; j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    w();

    cout << totalWeight;
}