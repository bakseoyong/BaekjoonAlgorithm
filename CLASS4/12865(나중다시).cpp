#include <iostream>
using namespace std;

int dp[100001] = { 0, };

int main(){
    int N, K;   

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        dp[a] = b;
    }

    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= i/2; j++){
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }

    // for(int i = 1; i <= K; i++){
    //     cout << "dp[" << i <<"] value :" << dp[i] << endl;
    // }


    cout << dp[K];
}