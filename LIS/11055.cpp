#include <iostream>
using namespace std;

int main(){
    int N;
    int arr[1000];
    int dp[1000] = { 0, };
    int ans;

    cin >> N;

    for(int i =0; i < N; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }

    ans = dp[0];

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]){
               dp[i] = dp[j] + arr[i];
               if(ans < dp[i]) ans = dp[i];
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << " " << dp[i];
    }

    cout << ans;
}