#include <iostream>
#include <deque>
using namespace std;

int main(){
    int K, a;
    deque<int> q;
    cin >> K;
    

    for(int i = 0; i < K ; i++){
        cin >> a;
        if(a == 0){
            q.pop_back();
            continue;
        }
        q.push_back(a);
    }

    int t = 0;
    while(!q.empty()){
        t += q.front();
        q.pop_front();
    }

    cout << t;
}