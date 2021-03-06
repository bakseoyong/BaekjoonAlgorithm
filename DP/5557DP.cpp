#include <iostream>
using namespace std;

int N;
int arr[101] = { 0, };
long dp[101][21] = { 0, };

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    dp[0][arr[0]] = 1;

    for(int i = 1 ; i < N - 1; i++){
        for(int j = 0; j <= 20; j++){
            if(dp[i-1][j] != 0){
                if(j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i-1][j];
                if(j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i-1][j];
            }
        }
    }

    cout << dp[N-2][arr[N-1]];
}