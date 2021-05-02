#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<int> b, c;
    int temp;
    int answer;

    cin >> temp;
    while( temp != 0 ) {

        answer = temp;

        while(temp >= 10){
            b.push(temp%10);
            temp /= 10;
        }
        b.push(temp);

        int ss = 0;
        int h = 1;
        while(!b.empty()){
            ss += b.top() * h;
            b.pop();
            h *= 10;
        }

        if(answer == ss) cout << "yes" << endl;
        else cout << "no" << endl;

        cin >> temp;
    }
}