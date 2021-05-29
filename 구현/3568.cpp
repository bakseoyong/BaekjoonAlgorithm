#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string input, char delimeter){
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while(getline(ss, temp, delimeter)){
        answer.push_back(temp);
    }

    return answer;
}

vector<string> erase(vector<string> input){
    for(int i = 1; i < input.size(); i++){
        for(int j = 0; j < input[i].length(); j++){
            if(input[i][j] == ',' || input[i][j] == ';')
                input[i].erase(j, 1);
        }
    }

    return input;
}

int main(){
    string s;
    getline(cin, s);
    vector<string> result = split(s, ' ');
    result = erase(result);

    for(int i = 1; i < result.size(); i++){
        string type;
        string variableName;
        type = result[0];

        for(int j = result[i].length() - 1; j >= 0; j--){
            if(result[i][j] == ']'){
                type += "[]";
                j--;
            }
            else if(result[i][j] == '&' || result[i][j] == '*'){
                type += result[i][j];
            }
            else{
                variableName += result[i][j];
            }
        }

        cout << type << " ";
        for(int k = variableName.length() - 1; k >= 0; k--){
            cout << variableName[k];
        }
        cout << ";" << endl;
        
    }
}