#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int N;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    int a;

    cin >> N;

    for(int i =0 ; i < N; i++){
        cin >> a;
        if(a == 0){
            if(!pq.empty()){
                cout <<pq.top().second << endl;
                pq.pop();
            }
            else
                cout << 0 << endl;
        }else{
            pq.push(make_pair(abs(a), a));
        }
    }
}