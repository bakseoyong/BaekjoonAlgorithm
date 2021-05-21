#include <iostream>
#include <vector>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
};

int main(){
    int dp[1000] = { 0 , };
    int arr[1000];
    int ans[1000][1000];
    int anw = 1;
    int ansIdx = 0;

    int N;
    cin >> N;

    for(int i = 0; i< N; i++){
        cin>> arr[i];
        dp[i] = 1;
    }

    ans[0][1] = arr[0];

    for(int i = 0; i < N; i++){
        for(int j = 1; j < i; j++){
            if( arr[i] > arr[j] && dp[i] < dp[j] + 1){
                cout << " ================ " << i << endl;
                dp[i] = dp[j] + 1;
                if(anw < dp[i]) {
                    ansIdx = i;
                    anw = dp[i];
                    ans[i][anw] = arr[i];
                    for(int t = 1; t < anw; t++){
                        ans[i][t] = ans[j][t];
                    }
                }
            }
        }
    }

    for(int i = 0; i < anw; i++){
        cout << ans[ansIdx][i] << " ";
    }

    cout << endl << ans[1][0] << " " << ans[1][1];
}