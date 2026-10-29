#include <string>
#include <iostream>
using namespace std;


int main(){
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i ++){
        if(i != str.size() / 2){
            cout << str[i];
        }
    }
    cout << endl;
}