#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K;
long long input[1000000];
long long *tree;

long long init(int idx, int start, int end){
    if(start == end) tree[idx] = input[start];
    else tree[idx] = init(idx*2+1, start, (start+end)/2) + init(idx*2+2, (start+end)/2+1, end);

    return tree[idx];
}

void update(int chgIdx, long long diff, int idx, int start, int end){
    if(chgIdx < start || chgIdx > end) return;

    tree[idx] += diff;

    if(start != end){
        int mid = (start+end)/2;
        update(chgIdx, diff, idx*2+1, start, mid);
        update(chgIdx, diff, idx*2+2, mid+1, end);
    }
}

long long getSum(int idx, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    else if(left <= start && right >= end) return tree[idx];

    int mid = (start+end)/2;
    return getSum(idx*2+1, start, mid, left, right) + getSum(idx*2+2, mid+1, end, left, right);
}

int main(){
    int h, tree_size;

    cin >> N >> M >> K;
    h = ceil(log2(N));
    tree_size = 1 << (h + 1);

    tree = new long long[tree_size];

    for(int i = 0; i < N; i++)
        cin >> input[i]; 

    init(0, 0, N-1);

    for(int i = 0; i < M+K; i++){
        int a, b;

        cin >> a >> b;
        if(a == 1){
            long long c;
            cin >> c;

            long long diff = c - input[b-1];
            input[b-1] = c;
            
            update(b-1, diff, 0, 0, N-1);
        }else{
            int c;
            cin >> c;

            cout << getSum(0, 0, N-1, b-1, c-1) << endl; // 2 ~ 5 => 인덱스 1 ~ 4
        }
    }
}