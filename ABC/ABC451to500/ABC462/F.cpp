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



void solveCase(){
    string S;
    ll K;
    ll charCnt = 0;
    ll ABCcnt = 0;
    for(ll i = 0; i < S.size(); i ++){
        if(S[i] == 'A'){
            charCnt = 1;
        }else if(S[i] == 'B' && charCnt == 1){
            charCnt = 2;
        }else if(S[i] == 'C' && charCnt == 2){
            charCnt = 0;
            ABCcnt ++;
        }else{
            charCnt = 0;
        }

    }
}
int main(){
    
}