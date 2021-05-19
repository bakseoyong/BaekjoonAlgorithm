#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[1000];
    int dp[1000] = { 0, };
    int ans;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    ans = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                if(ans < dp[i]) ans = dp[i];
            }
        }
    }

    cout << ans;
}