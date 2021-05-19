#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int st = 0;
    
    stack<char> stack;
    vector<char> v;

    for(int i = 0; i < s.length(); i++){
        if(s[i] - 65 >= 0 && s[i] - 65 <= 25){
            cout << s[i];
            if(st == 1){
                cout << stack.top();
                stack.pop();
                //st = 0;
            }
            continue;
        }
        else if(s[i] == '(') {
            st = 0;
            continue;
        }
        else if(s[i] == ')'){
            char temp = stack.top();
            stack.pop();
            cout << temp;
        }
        else if(s[i] == '*' || s[i] == '/'){
            stack.push(s[i]);
            st = 1;
            continue;
        }
        else if(s[i] == '+' || s[i] == '-'){
            stack.push(s[i]);
            continue;
        }
    }

    while(!stack.empty()){
        char top = stack.top();
        stack.pop();
        cout << top;
    }
}