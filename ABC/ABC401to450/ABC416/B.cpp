#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    string resultStr = "";
    bool push = true;
    for(int i = 0; i < str.length(); i ++){
        if(str[i] == '.'){
            if(push){
                resultStr += "o";
                push = false;
            }
            else{
                resultStr += ".";
            }
            
        }
        else{
            resultStr += "#";
            push = true;
        }
    }
    cout << resultStr << endl;
}