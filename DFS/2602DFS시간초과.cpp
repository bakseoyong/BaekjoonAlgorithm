#include <iostream>
#define DEVIL 1
#define ANGEL 2
using namespace std;

string s1;
string s2; //악마의 돌다리
string s3; //천사의 돌다리

long answer = 0;

void DFS(int bridgeNum, int s1Idx, int bridgeIdx){
    if(bridgeIdx >= s2.length()) //문자열을 전부 탐색한 경우
        return;
    else if(bridgeNum == ANGEL){ //천사의 돌다리에서 탐색
        for(int i = bridgeIdx; i < s3.length(); i++){
            
            if(s3[i] == s1[s1Idx]){ 
                //cout << " i : " << i << "   s3[i]  : " << s3[i] << " s1 idx : " << s1Idx << endl;
                if(s3[i] == s1[s1Idx] && s1Idx == s1.length() - 1){ 
                    //cout << bridgeNum << " " << bridgeIdx << s1[s1Idx] << endl;
                    answer++;
                }
                //돌다리 변경, 다음 인덱스 부터, 다음 다리부터
                DFS(DEVIL, s1Idx + 1, i + 1);
            }
        }
    }else if(bridgeNum == DEVIL){ //악마의 돌다리에서 탐색
        for(int i = bridgeIdx; i < s2.length(); i++){

            if(s2[i] == s1[s1Idx]){
                //cout << " i : " << i << "  s2[i]  : " << s2[i] << " s1 idx : " << s1Idx << endl;
                if(s1Idx == s1.length() - 1){
                    //cout << bridgeNum << " " << bridgeIdx << s1[s1Idx] << endl;
                    answer++;
                }
                //돌다리 변경, 다음 인덱스 부터, 다음 다리부터
                DFS(ANGEL, s1Idx + 1, i + 1);
            }
        }
    }
}

int main(){
    cin >> s1;
    cin >> s2;
    cin >> s3;

    //악마의 돌다리부터 첫번째 요소를 탐색
    DFS(DEVIL, 0, 0);
    //천사의 돌다리부터 첫번째 요소를 탐색
    DFS(ANGEL, 0, 0);

    cout << answer;
}