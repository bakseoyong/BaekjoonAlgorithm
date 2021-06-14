#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string word[50];
int alphabet[26] = { 0, };
int N, K;
int total = 0;

void necessaryWord(){
    alphabet[0] = 1; //a
    alphabet[2] = 1; //c
    alphabet[8] = 1; //i
    alphabet[13] = 1; //n
    alphabet[19] = 1; //t
}

void recursive(int idx, int cnt){
    
    if(cnt == K - 5){
        int temp = N;
        //단어들에 탐색을 돌린다.
        for(int j = 0; j < N; j++){

            for(int t = 0; t < word[j].length(); t++){
                if(alphabet[word[j][t] - 97] == 0) {
                    temp--;
                    break;
                }
            }

        }

        total = max(temp, total);
        return;
    }

    if(idx >= 26) return;

    for(int i = idx; i < 26; i++){
        if(alphabet[i] == 0){
            alphabet[i] = 1;
            recursive(i + 1, cnt + 1);
            alphabet[i] = 0;
        }
    }

}

int main(){
    cin >> N >> K;
   
    for(int i = 0; i < N; i++){
        cin >> word[i];

        word[i] = word[i].substr(4, word[i].length());
        word[i] = word[i].substr(0, word[i].length() - 4);
    }

    if(K < 5) {
        cout << 0 << endl;
        return 0;
    }

    if(K == 26){
        cout << N << endl;
        return 0;
    }

    necessaryWord();

    recursive(0, 0);

    cout << total << endl;

}