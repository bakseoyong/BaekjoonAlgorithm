#include <iostream>
#include <algorithm>
#define INF 1000000001
using namespace std;

int main(){
    int N;
    vector<int> vt;
    vt.push_back(-INF);

    cin >> N;

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        if( a > vt.back()){
            vt.push_back(a);
        }else if( a < vt.back()){
            auto au = lower_bound(vt.begin(), vt.end(), a);
            //cout << a << endl;
            *au = a;
        }
    }

    cout << vt.size() - 1 << endl;
    for(int i = 0; i < vt.size(); i++){
        cout << vt[i] << " ";
    }
}