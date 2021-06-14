#include <iostream>
using namespace std;

int N, K;
int arr[100];
int multi[100] = { 0, };
int arrIdx = 0;
int change = 0;


//멀티탭에 존재하는지 확인하는 함수
bool isHave(int arrIdx){
    for(int i = 0; i < N; i++){
        if(multi[i] == arr[arrIdx])
            return true;
    }
    return false;
}

void initMultiTap(){
    int idx = 0;

    while(idx != N){
        if(!isHave(arrIdx)){ //멀티탭에 존재하지 않다면
            multi[idx++] = arr[arrIdx++];
        }
        else{ //멀티탭에 존재한다면
            arrIdx++;
        }
    }
}



void a(){
    //멀티탭을 꽉 채우기 전
    initMultiTap();

    //멀티탭이 꽉찬 경우
    for(int i = arrIdx; i < K; i++){

        if(isHave(i)) continue;
        //멀티탭이 차고, 이번에 수행할 작업이 새로운 콘센트라면
        else{

            int tempMulti[100] = { 0, };

            //나중에 수행할 작업이 이미 콘센트가 있는 작업인지 확인한다.
            for(int j = 1; j < N; j++){
                if(i+j >= K) continue;

                if(isHave(i+j)){ //다음 수행할 작업에 필요한 콘센트가 있다면 그 콘센트는 안 뽑아야지
                    //그 콘센트가 몇번째 위치인지 확인
                    for(int k = 0; k < N; k++){
                        if(arr[i+j] == multi[k]){ //확인된다면
                            tempMulti[k] = 1;
                        }
                    }
                }
            }

            //나중 작업이 몇번째 콘센트에 있는지 확인 후, 다음 작업에 필요없는 콘센트를 변경한다.
            for(int k = 0; k < N; k++){
                if(tempMulti[k] == 0){
                    //cout << "change :" << i << endl;
                    multi[k] = arr[i];
                    change++;
                    break;
                }
            }
        }
    }
}

int main(){
    cin >> N >> K;

    for(int i =0; i < K; i++)
        cin >> arr[i];

    a();   

    cout << change;
}