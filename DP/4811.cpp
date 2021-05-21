#include <iostream>
using namespace std;


long long int dp[1001][1001] = { 0, };

long long int recursive(long long int a, long long int b){
    long long int a1, a2;

    if(dp[a][b] == 0){
        if(a > 0)
            a1 = recursive(a-1, b+1);
        else{
            a1 = 0;
        }
        if(b > 0)
            a2 = recursive(a, b-1);
        else{
            a2 = 0;
        }
        dp[a][b] = a1 + a2;
    }

    return dp[a][b];
}

int main(){
    int a;

    dp[1][0] = 1;
    dp[0][1] = 1;
    dp[0][0] = 1;

    cin >> a;
    while(a != 0){
        cout << recursive(a, 0) << endl;
        cin >> a;
        
    }
    
}