#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T, N;
    int a, b;
    int Cnt, cmpRank;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        vector<pair<int, int> > rank;
        Cnt = N;

        for(int j = 0; j < N; j++){
            cin >> a >> b;
            rank.push_back(make_pair(a, b));
        }

        sort(rank.begin(), rank.end());

        cmpRank = rank[0].second;

        for(int k = 1; k < N; k++){
            if(rank[k].second > cmpRank){
                Cnt--;
            }
            cmpRank = cmpRank > rank[k].second ? rank[k].second : cmpRank;
        }

        cout << Cnt << endl;
    }
}