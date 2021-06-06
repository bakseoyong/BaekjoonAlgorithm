#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string s1, s2, s3, s4;
int K;
queue<pair<int, int> > q;
bool visited[5];
int answer = 0;

string Rot(string s){
    string tempS = s;
    for(int i = 1; i < 8; i++){
        s[i] = tempS[i-1];
    }
    s[0] = tempS[7];

    return s;
}

string revRot(string s){
    string tempS = s;
    for(int i = 6; i >= 0; i--){
        s[i] = tempS[i+1];
    }
    s[7] = tempS[0];

    return s;
}

//3시방향 s1[2] 9시방향 s1[6]
void abc(){
    while(!q.empty()){
        memset(visited, false, sizeof(visited));
        int gearNum = q.front().first;
        int dir = q.front().second;
        q.pop();

        queue<pair<int, int> > tempQ;
        tempQ.push(make_pair(gearNum, dir));

        while(!tempQ.empty()){
            gearNum = tempQ.front().first;
            dir = tempQ.front().second;
            tempQ.pop();
            //큐에 추가할때 visited를 살피면 여기서 visited를 안살펴도 된다
            if(gearNum == 1){
                
                
                visited[1] = true;

                if(s1[2] != s2[6] && visited[2] == false){
                    
                    tempQ.push(make_pair(2, -dir));

                    
                }

                if(dir == 1){
                    s1 = Rot(s1);
                }else
                    s1 = revRot(s1);

            }else if(gearNum == 2){ //본인부터 시작하는 경우, 남에게 와서 시행 된 경우
                

                visited[2] = true;

                if(visited[1] == false){
                    if(s1[2] != s2[6]){
                        
                        tempQ.push(make_pair(1, -dir));
                    }
                }

                if(visited[3] == false){
                    if(s2[2] != s3[6]){
                        
                        tempQ.push(make_pair(3, -dir));
                    }
                }

                if(dir == 1){
                    s2 = Rot(s2);
                }else
                    s2 = revRot(s2);

            }else if(gearNum == 3){
                

                visited[3] = true;

                if(visited[2] == false){
                    if(s2[2] != s3[6]){
                        

                        tempQ.push(make_pair(2, -dir));
                    }
                }

                if(visited[4] == false){
                    if(s3[2] != s4[6]){
                        
                        tempQ.push(make_pair(4, -dir));
                    }
                }

                if(dir == 1){
                    s3 = Rot(s3);
                }else
                    s3 = revRot(s3);

            }else if(gearNum == 4){
                
                visited[4] = true;

                if(s4[6] != s3[2] && visited[3] == false){
                    
                    tempQ.push(make_pair(3, -dir));
                }

                if(dir == 1){
                    s4 = Rot(s4);
                }else
                    s4 = revRot(s4);

            }
        }
    }

    //N이 0  , S가 1
    if(s1[0] == '1') answer += 1;
    if(s2[0] == '1') answer += 2;
    if(s3[0] == '1') answer += 4;
    if(s4[0] == '1') answer += 8;


}

int main(){
    int a, b;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    cin >> s4;
    

    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        q.push(make_pair(a, b));
    }

    abc();

    cout << answer;
}