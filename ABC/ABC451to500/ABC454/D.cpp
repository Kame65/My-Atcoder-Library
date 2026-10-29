#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <string>

using ll = long long int;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


string simple(string str){
    ll N = str.size();
    vector <char> vecS;
    for(ll i = 0; i < N; i ++){
        vecS.push_back(str[i]);
        while(true){
            ll size = vecS.size();
            if(size < 4){
                break;
            }
            // cout << (vecS[size - 1] == ')' && vecS[size - 2] == 'x' && vecS[size - 3] == 'x') << endl;
            // cout << vecS[size - 1]  << vecS[size - 2]  << vecS[size - 3] << vecS[size - 4] << endl;;
            if(vecS[size - 1] == ')' && vecS[size - 2] == 'x'
             && vecS[size - 3] == 'x' && vecS[size - 4] == '('){
                vecS[size - 4] = 'x';
                vecS.pop_back();
                vecS.pop_back();
                // cout << "Pop" <<endl;
            }else{
                break;
            }
        }
    }
    return string(vecS.begin(), vecS.end());
    
}
int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        string str1, str2;
        cin >> str1 >> str2;
        str1 = simple(str1);
        str2 = simple(str2);
        // cout << str1 << endl;
        // cout <<str2 << endl;
        if(str1 == str2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}