#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long int;


ll N;
vector<ll> vecA, dp;
unordered_map<ll, vector<ll>> valToIdx;

ll getDp(ll n){//nで終わる文字列の長さの最大を求める
    if(dp[n] > 0){
        return dp[n];
    }
    ll val = vecA[n];
    ll result = 1;
    for(ll i = 0; i < valToIdx[val - 1].size(); i ++){
        ll idx = valToIdx[val - 1][i];
        if(n < idx){
            continue;
        }
        if(result < getDp(idx) + 1){
            result = getDp(idx) + 1;
        }
    }
    dp[n] = result;
    return result;
}

int main(){
    cin >> N;
    vecA.resize(N);
    
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
        valToIdx[vecA[i]].push_back(i);
    }
    dp.resize(N, -1);
    dp[0] = 1;

    ll ans = 1;

    for(ll i = 0; i < N; i ++){
        if(ans < getDp(i)){
            ans = getDp(i);
        }
    }
    cout << ans << endl;




    
}