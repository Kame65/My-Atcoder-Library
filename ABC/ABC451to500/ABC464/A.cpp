#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


int main(){
    string S;
    ll e = 0;
    ll w = 0;
    cin >> S;
    for(ll i = 0; i < S.size(); i ++){
        if(S[i] == 'E'){
            e ++;
        }
        if(S[i] == 'W'){
            w ++;
        }
    }
    if(e > w){
        cout << "East" << endl;
    }
    if(e < w){
        cout << "West" << endl;
    }
    
}