#include <iostream>
#include <stack>
#include <string>
using namespace std;

int arr[100001];
stack<int> s;
int Cnt = 1;
string plusMinus = "";

int main(){
    int n;
    cin >> n;

    s.push(1);
    plusMinus += "+\n";

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){

        if(s.empty()) {
            s.push(++Cnt);
            plusMinus += "+\n";
        }

        while(arr[i] != s.top()){
            if(Cnt > n) {
                break;
            }
            s.push(++Cnt);
            plusMinus += "+\n";
        }


        if(arr[i] == s.top())
        {
            s.pop();
            plusMinus += "-\n";
        }
    }

    if(!s.empty()) cout << "NO" << endl;
    else cout << plusMinus;
}