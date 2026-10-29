#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;

int main(){
    string S;
    cin >> S;
    string resultS = "Of";
    for(ll i= 0; i < S.size(); i ++){
        if(i == 0){
            resultS += S[i] + 32;
        }else{
            resultS += S[i];
        }
    }
    cout << resultS << endl;
}