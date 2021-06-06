#include <iostream>
using namespace std;

int height[80000] =  { 0, };

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int sum = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> height[i];
    }

    for(int i = 0; i < N; i++){
        int curBdHeight = height[i];
        int cnt = 0;
        for(int j = i + 1; j < N; j++){
            if(curBdHeight > height[j]){
                cnt++;
            }
            else break;
        }
        //cout << "cnt :: " << cnt << endl;
        sum += cnt;
    }

    cout << sum;
}