#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int a = N;
    int b = K;
    int c = K;
    if(K == 0){
        cout << 1;
        return 0;
    }
    for(int i = 1; i < K; i++){
        N--;
        a *= N;
        
        c--;
        b *= c;
    }

    a /= b;
    cout << a;
}