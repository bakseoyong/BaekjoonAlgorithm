#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll input[100001];
ll* minTree;
ll* maxTree;

ll minInit(int idx, int start, int end){
    if(start == end) {
        minTree[idx] = input[start];
    }else{
        int mid = (start + end) / 2;

        minTree[idx] = min(minInit(idx*2+1, start, mid),minInit(idx*2+2, mid+1, end));
    }

    return minTree[idx];
}

ll maxInit(int idx, int start, int end){
    if(start == end){
        maxTree[idx] = input[start];
    }else{
        int mid = (start+end) / 2;

        maxTree[idx] = max(maxInit(idx*2+1, start, mid), maxInit(idx*2+2, mid+1, end));
    }

    return maxTree[idx];
}

ll getMin(int idx, int start, int end, int left, int right){
    if(left > end || right < start) return 9999999999;
    else if(start >= left && right >= end) return minTree[idx];
    else{
        int mid = (start + end) / 2;
        return min(getMin(idx*2+1, start, mid, left, right), getMin(idx*2+2, mid+1, end, left, right));
    }
}

ll getMax(int idx, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    else if(start >= left && right >= end) return maxTree[idx];
    else{
        int mid = (start + end) / 2;
        return max(getMax(idx*2+1, start, mid, left, right), getMax(idx*2+2, mid+1, end, left, right));
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;
    int h, tree_size;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> input[i];
    
    h = ceil(log2(N));
    tree_size = 1 << (h+1);


    minTree = new long long[tree_size];
    maxTree = new long long[tree_size];

    minInit(0, 0, N-1);
    maxInit(0, 0, N-1);


    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        cout << getMin(0, 0, N-1, a-1, b-1) << " " << getMax(0, 0, N-1, a-1, b-1) << "\n";
    }


    delete minTree;
    delete maxTree;
    
}