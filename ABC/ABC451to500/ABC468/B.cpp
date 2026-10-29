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
    ll M, D;
    cin >> M >> D;
    string S;
    cin >> S;
    vector<bool> judge(M, true);
    for(ll i = 0; i < M; i ++){
        if(S[i] == 'G'){
            for(ll j = 0; j <= D; j ++){
                if(i + j < M){
                    judge[i + j] = false;
                }
                if(i - j >= 0){
                    judge[i - j] = false;
                }
                
            }
        }
    }
    ll ans;
    for(ll i = 0; i < M; i ++){
        if(judge[i]){
            ans ++;
        }
    }
    cout << ans << endl;
}