#include <iostream>
#include <queue>
#define DEVIL 1
#define ANGEL 2
using namespace std;

string s1;
string s2; //악마의 돌다리
string s3; //천사의 돌다리

long answer = 0;

void BFS(){
    queue<pair<int , pair<int , int> > > q;


    //s1의 첫번째 문자와 일치한 s2의 인덱스 값들을 전부 집어넣는다.
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] == s1[0]){
            q.push(make_pair(DEVIL, make_pair(i, 0))); //악마의 돌다리에서 건넜으며, i번째 인덱스이다.
        }
    }

    for(int i = 0; i < s3.length(); i++){
        if(s3[i] == s1[0]){
            q.push(make_pair(ANGEL, make_pair(i, 0)));
        }
    }

    while(!q.empty()){
        int bridge = q.front().first;
        int idx = q.front().second.first;
        int s1Idx = q.front().second.second;
        q.pop();

        //cout << bridge << " " << idx << " " << s1Idx << endl;
        
        if(s1Idx == s1.length() - 1){ //큐에 들어왔다는 것은 s1의 어딘가의 문자와 동일했다는 것인데, 그 문자의 인덱스 값이 s1.length() - 1이라면
            answer++;
            continue;
        }else{ //s1의 어느 문자와 동일하지만, 도착한 것은 아닐 때, 반대편의 다리에서 다음 문자를 발견해서 그 문자를 밟아야 한다.
            if(bridge == ANGEL){ //내가 ANGEL을 밟아 이 위치에 도달했고, 악마의 돌다리를 밟아야 할 때
                for(int i = idx + 1; i < s2.length(); i++){
                    if(s2[i] == s1[s1Idx + 1]) {//반대편 다리에서 다음 인덱스부터 찾고 있는데, 다음에 밟아야 할 문자가 발견된다면
                        q.push(make_pair(DEVIL, make_pair(i, s1Idx + 1))); //악마 돌다리이며, i번쨰 인덱스에서 발견했고, 이 발견한 문자는 s1에서 s1Idx + 1 번째 문자임을 저장.
                    }
                }
            }else if(bridge == DEVIL){
                for(int i = idx + 1; i < s3.length(); i++){
                    if(s3[i] == s1[s1Idx + 1]) {//반대편 다리에서 다음 인덱스부터 찾고 있는데, 다음에 밟아야 할 문자가 발견된다면
                        q.push(make_pair(ANGEL, make_pair(i, s1Idx + 1))); //천사 돌다리이며, i번쨰 인덱스에서 발견했고, 이 발견한 문자는 s1에서 s1Idx + 1 번째 문자임을 저장.
                    }
                }
            }
        }
    }
}

int main(){
    cin >> s1;
    cin >> s2;
    cin >> s3;

    BFS();

    cout << answer;
}