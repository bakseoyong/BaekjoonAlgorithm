#include <iostream>
using namespace std;

int height[80000] =  { 0, };

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long int sum = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> height[i];
    }

    for(int i = 0; i < N; i++){
        int curBdHeight = height[i];
        int cnt = 0;
        for(int j = i + 1; j < N; j++){
            if(curBdHeight > height[j]){
                height[j - 1] = 0;
                cnt++;
            }
            else break;
        }
        //cout << "cnt :: " << cnt << endl;
        sum += cnt;
    }

    cout << sum;
}


#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h, ans = 0, max=0;
	vector<int>v;
	stack<pair<int, int>>k;

	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> h;
		v.push_back(h);
		if (h > max)max = h;
	}

	k.push(make_pair(max+1, n)); //13, 6

	for(int i=n-1;i>=0;i--) {
		while (!k.empty()) {
			if (k.top().first >= v.back()) {
				ans += k.top().second - i-1;
				break;
			}
			k.pop();
		}
		k.push(make_pair(v.back(), i));
		v.pop_back();
	}
	cout << ans;
}