#include <iostream>
using namespace std;

int N;
int map[500][500] = {0, };
int sum = 0;

float leftSwift[5][5] = {
    {0, 0, 0.02, 0, 0},
    {0, 0.1, 0.07, 0.01, 0},
    {0.05, 0, 0, 0, 0},
    {0, 0.1, 0.07, 0.01, 0},
    {0, 0, 0.02, 0, 0}
};

float rightSwift[5][5] = {
    {0, 0, 0.02, 0, 0},
    {0, 0.01, 0.07, 0.1, 0},
    {0, 0, 0, 0, 0.05},
    {0, 0.01, 0.07, 0.1, 0},
    {0, 0, 0.02, 0, 0}
};

float upSwift[5][5] = {
    {0, 0, 0.05, 0, 0},
    {0, 0.1, 0, 0.1, 0},
    {0.02, 0.07, 0, 0.07, 0.02},
    {0, 0.01, 0, 0.01, 0},
    {0, 0, 0, 0, 0}
};

float downSwift[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0.01, 0, 0.01, 0},
    {0.02, 0.07, 0, 0.07, 0.02},
    {0, 0.1, 0, 0.1, 0},
    {0, 0, 0.05, 0, 0}
};

int main(){
    cin >> N;
    int y = N/2;
    int x = N/2;
    int tempSum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 1; i < N; i++){
        

        for(int j = 0; j < i; j++){
            x -= 1;
            for(int k = -2; k <= 2; k++){
                for(int q = -2; q <= 2; q++){ // 가운데가 2,2 이므로 up[2+k][2+q]
                    if(leftSwift[2+k][2+q] != 0){
                        int intValue = int(map[y][x] * leftSwift[2+k][2+q]);
                        if(intValue > 0){
                            if(y+k >= 0 && y+k < N && x+q >= 0 && x+q < N){
                                map[y+k][x+q] += intValue;
                            }
                            else
                                sum += intValue;

                            tempSum += intValue;   
                        }                     
                    }
                }
            }
            if(x > 0)
                map[y][x-1] = map[y][x] - tempSum;
            else
                sum += (map[y][x] - tempSum);
            cout << "y " << y << "x-1 " << x-1 << "mapyx-1  " << map[y][x-1] << endl; 
            map[y][x] = 0;
            tempSum = 0;
        }

        for(int j = 0; j < i; j++){
            y += 1;
            for(int k = -2; k <= 2; k++){
                for(int q = -2; q <= 2; q++){ // 가운데가 2,2 이므로 up[2+k][2+q]
                    if(downSwift[2+k][2+q] != 0){
                        int intValue = int(map[y][x] * downSwift[2+k][2+q]);
                        if(intValue > 0){
                            if(y+k >= 0 && y+k < N && x+q >= 0 && x+q < N){
                                map[y+k][x+q] += intValue;
                            }
                            else
                                sum += intValue;
                            
                            tempSum += intValue;
                        }
                    }
                }
            }
            if(y < N)
                map[y+1][x] = map[y][x] - tempSum;
            else
                sum += (map[y][x] - tempSum);
            cout << "y+1" << y + 1 << "x " << x << "mapyx-1  " << map[y+1][x] << endl; 

            map[y][x] = 0;
            tempSum = 0;

        }

        i++;

        for(int j = 0; j < i; j++){
            x += 1;
            for(int k = -2; k <= 2; k++){
                for(int q = -2; q <= 2; q++){ // 가운데가 2,2 이므로 up[2+k][2+q]
                    if(leftSwift[2+k][2+q] != 0){
                        int intValue = int(map[y][x] * rightSwift[2+k][2+q]);
                        if(intValue > 0){
                            if(y+k >= 0 && y+k < N && x+q >= 0 && x+q < N)
                                map[y+k][x+q] += intValue;
                            else
                                sum += intValue;

                            tempSum += intValue;
                        }
                    }
                }
            }
            if(x < N)
                map[y][x+1] = map[y][x] - tempSum;
            else
                sum += (map[y][x] - tempSum);
            map[y][x] = 0;
            tempSum = 0;

        }

        for(int j = 0; j < i; j++){
            y -= 1;
            for(int k = -2; k <= 2; k++){
                for(int q = -2; q <= 2; q++){ // 가운데가 2,2 이므로 up[2+k][2+q]
                    if(leftSwift[2+k][2+q] != 0){
                        int intValue = int(map[y][x] * upSwift[2+k][2+q]);
                        if(intValue > 0){
                            if(y+k >= 0 && y+k < N && x+q >= 0 && x+q < N){
                                map[y+k][x+q] += intValue;
                            }
                            else
                                sum += intValue;

                            tempSum += intValue;
                        }
                    }
                }
            }
            if(y > 0)
                map[y-1][x] = map[y][x] - tempSum;
            else
                sum += (map[y][x] - tempSum);
            map[y][x] = 0;
            tempSum = 0;


        }
    }

    cout << "? " << endl;

    for(int j = 1; j < N; j++){
        x -= 1;
        for(int k = -2; k <= 2; k++){
            for(int q = -2; q <= 2; q++){ // 가운데가 2,2 이므로 up[2+k][2+q]
                if(leftSwift[2+k][2+q] != 0){
                    int intValue = int(map[y][x] * leftSwift[2+k][2+q]);
                    if(intValue > 0){
                        if(y+k >= 0 && y+k < N && x+q >= 0 && x+q < N){
                            map[y+k][x+q] += intValue;
                        }
                        else
                            sum += intValue;

                        tempSum += intValue;
                    }
                }
            }
        }
        if(x > 0)
            map[y][x-1] = map[y][x] - tempSum;
        else
            sum += (map[y][x] - tempSum);
        map[y][x] = 0;
        tempSum = 0;


    }



    cout << sum;
}