#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[200];
int dp[200];

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
}