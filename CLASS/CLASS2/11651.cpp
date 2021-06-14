#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    
    if (a.second == b.second ) return a.first < b.first;
    else
     return a.second < b.second;
}

int main(){
    int N;
    cin >> N;
    int a, b;

    v.resize(N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end(), cmp);


    for(int i = 0; i < N; i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
}
