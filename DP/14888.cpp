#include <iostream>
using namespace std;

int N;
int num[100];
int oper[4];
int maxValue = -1000000001;
int minValue = 1000000001;

void DFS(int calIdx, int sum){
    if(calIdx == N){
        maxValue = max(maxValue, sum);
        minValue = min(minValue, sum);
        return;
    }

    int saveSum = sum;

    for(int i = 0; i < 4; i++){
        if(oper[i] != 0){
            oper[i]--;
            if(i==0){
                sum += num[calIdx];
                DFS(calIdx + 1, sum);
                oper[i]++;
                sum = saveSum;
            }else if(i==1){
                sum -= num[calIdx];
                DFS(calIdx + 1, sum);
                oper[i]++;
                sum = saveSum;
            }else if(i==2){
                sum *= num[calIdx];
                DFS(calIdx + 1, sum);
                oper[i]++;
                sum = saveSum;
            }else{
                sum /= num[calIdx];
                DFS(calIdx + 1, sum);
                oper[i]++;
                sum = saveSum;
            }
        }
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> oper[i];
    }

    DFS(1, num[0]);

    cout << maxValue << endl << minValue;
}