#include <iostream>
using namespace std;

int N;
int arr[100];
int anw = 0;

void DFS(int cnt, int sum){
    if(cnt == N-1){
        if(sum == arr[N-1]){
            anw++;
        }
        return;
    }

    else{
        if(sum + arr[cnt] <= 20)
            DFS(cnt + 1, sum + arr[cnt]);
        if(sum - arr[cnt] >= 0)
            DFS(cnt + 1, sum - arr[cnt]);
    }

}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    DFS(0, 0);

    cout << anw;
}