#include <iostream>
#include <queue>
using namespace std;

int day = 0;
queue<pair<pair<int, int>, int> > tomatoQueue;
int todayTomatoNum = 0;
int tomorrowTomatoNum = 0;
int isFinish = 0;

int findAnswer(int M, int N, int H, int box[100][100][100]){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(box[i][j][k] == 0){
                    return -1;
                }
            }
        }
    }

    return 1;
}

//하루 주기로 재귀호출
int spreadTomato(int M, int N, int H, int box[100][100][100]){
    int dz[6] = {0, 0, 0, 0, -1, 1};
    int dy[6] = {0, 1, 0, -1, 0, 0};
    int dx[6] = {-1, 0, 1, 0, 0, 0};
    int x, y, z;


    while(todayTomatoNum){
        z = tomatoQueue.front().first.first;
        y = tomatoQueue.front().first.second;
        x = tomatoQueue.front().second;
        tomatoQueue.pop();
        todayTomatoNum--;

        for(int i = 0; i < 6; i++){
            if(z + dz[i] < 0 || z + dz[i] >= H) continue;
            if(y + dy[i] < 0 || y + dy[i] >= N) continue;
            if(x + dx[i] < 0 || x + dx[i] >= M) continue;
            if(box[z+dz[i]][y+dy[i]][x+dx[i]] == 0){
            	box[z+dz[i]][y+dy[i]][x+dx[i]] = 1;
                tomatoQueue.push(make_pair(make_pair(z+dz[i], y+dy[i]), x+dx[i]));
                tomorrowTomatoNum++;
            }   
        }
    }

    if(tomorrowTomatoNum == 0){
    	isFinish = 1;
        return 0;
    }
    
	day++;
    todayTomatoNum = tomorrowTomatoNum;
    tomorrowTomatoNum = 0;
    spreadTomato(M, N, H, box);
    if(isFinish == 1){
    	return 0;
    }
}

int main(){
    int M, N, H;
    int box[100][100][100];

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> box[i][j][k];
            }
        }
    }

    //DFS로 익은토마토 전파
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(box[i][j][k] == 1){
                    tomatoQueue.push(make_pair(make_pair(i, j), k));
                    todayTomatoNum++;
                }
            }
        }
    }
	int test = 571;
    if(todayTomatoNum != 0){
        test = spreadTomato(M, N, H, box);
    }
    else{
        cout << -1;
        return 0;
    }
	

    //익지 않은 토마토가 있는지 탐색
    if(findAnswer(M, N, H, box) == -1){
        cout << -1;
        return 0;
    }
    cout << day;
}