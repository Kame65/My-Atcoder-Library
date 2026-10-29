#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

vl pow8s;
ll pow8(ll n){
    if(pow8s[n] > 0){
        return pow8s[n];
    }
    if(n == 0){
        pow8s[n] = 1;
        return 1;
    }
    pow8s[n] = 8 * pow8(n - 1);
    return pow8s[n];

    
}

string change8to9(string s){
    ll result10 = 0;
    for(ll i = 0; i < s.size(); i ++){
        result10 += pow8(i) * (s[s.size() - 1 - i] - '0');
        // cout << (s[s.size() - 1 - i] - '0') << endl;
    }
    string result9 = "";
    vl result9s;
    while(1){
        ll beforeVal = result10 % 9;
        result9s.push_back(beforeVal);
        result10 -= beforeVal;
        result10 /= 9;
        if(result10 == 0){
            break;
        }
    }
    for(ll i = result9s.size() - 1; i >= 0; i --){
        result9 += result9s[i] + '0';
        // cout << result9 << endl;
        
    }
    
    // cout << result << endl;
    return result9;
}
string change9to8(string s){
    for(ll i = 0; i < s.size(); i ++){
        if(s[i] == '8'){
            s[i] = '5';
        }
    }
    return s;
}

int main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    pow8s = vl(21);
    for(ll i = 0; i < K; i ++){
        S = change8to9(S);
        // cout << S << endl;
        S = change9to8(S);
        
    }
    cout << S << endl;
    // cout << pow8(0) << endl;



}