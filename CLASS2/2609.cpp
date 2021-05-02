#include <iostream>
using namespace std;

int main(){
    int a, b;

    cin >> a >> b;

    if(a<b){
        int temp = b;
        b = a;
        a = temp;
    }

    for(int i = a; i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            cout << i << endl;
            break;
        }
    }

    int j = 1;
    int t = 1;
    while(a * j != b * t){
        if(a * j  < b * t) j++;
        else t++;
    }

    cout << a * j  << endl;
}