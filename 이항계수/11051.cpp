#include <iostream>
using namespace std;

int main(){
    int N, K;
    long long int dp[1001][1001];

    cin >> N >> K;

    if(K == 0){
        cout << 1;
        return 0;
    }
    
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                dp[i][j] = 1; 
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
            }
        }
    }

    cout << dp[N][K];
}