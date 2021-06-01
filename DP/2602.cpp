#include <iostream>
#include <queue>
#define DEVIL 1
#define ANGEL 2
using namespace std;

string s1;
string s2; //악마의 돌다리
string s3; //천사의 돌다리

long answer = 0;

void DP(){
    
}

int main(){
    cin >> s1;
    cin >> s2;
    cin >> s3;

    BFS();

    cout << answer;
}