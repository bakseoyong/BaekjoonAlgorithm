#include <iostream>
using namespace std;

int N;
int map[3], minDp[3], maxDp[3], leastMinDp[3], leastMaxDp[3];
int cnt = 0; //y == 0

void A(int idx){

    if(cnt++ < 3){
        maxDp[idx] = minDp[idx] = map[idx];
        //cout << " idx : " << idx << " minDp[idx] : " << minDp[idx] << endl;
        return;
    }

    if(idx == 0){
        minDp[0] = map[0] + min(leastMinDp[0], leastMinDp[1]);
        maxDp[0] = map[0] + max(leastMaxDp[0], leastMaxDp[1]);
    }else if(idx == 1){
        //cout << "idx == 1 DP : " << minDp[0] << " " << minDp[1] << " " << minDp[2] << endl;
        minDp[1] = map[1] + min(leastMinDp[0], min(leastMinDp[1], leastMinDp[2]));
        maxDp[1] = map[1] + max(leastMaxDp[0], max(leastMaxDp[1], leastMaxDp[2]));
    }else if(idx == 2){
        minDp[2] = map[2] + min(leastMinDp[1], leastMinDp[2]);
        maxDp[2] = map[2] + max(leastMaxDp[1], leastMaxDp[2]);
    }

    //cout << " idx : " << idx << " minDp[idx] : " << minDp[idx] << endl;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> map[j];
            A(j);
        }
        leastMinDp[0] = minDp[0];
        leastMinDp[1] = minDp[1];
        leastMinDp[2] = minDp[2];
        leastMaxDp[0] = maxDp[0];
        leastMaxDp[1] = maxDp[1];
        leastMaxDp[2] = maxDp[2];
    }

    int answerMin = min(minDp[0], min(minDp[1], minDp[2]));
    int answerMax = max(maxDp[0], max(maxDp[1], maxDp[2]));

    cout << answerMax << " " << answerMin;
}