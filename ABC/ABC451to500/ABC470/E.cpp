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


vector<vector<vector<long double>>> dp;//この後とれるペアの個数の期待値
vector<vector<vector<bool>>> done;
long double getDp(ll l, ll unk, ll nk){// LIFE, unknownNum, oneIsKnownNum

    if(done[l][unk][nk]){
        // cout << "memoReturn: " << dp[l][unk][nk] << endl;
        return dp[l][unk][nk];
    }
    done[l][unk][nk] = true;
    dp[l][unk][nk] = 0;
    if(l == 0){
        // cout << l << " " << unk << " " << nk << " " << dp[l][unk][nk] << endl;
        return 0;
    }
    if(unk == 0 && nk == 0){
        // cout << l << " " << unk << " " << nk << " " << dp[l][unk][nk] << endl;
        return 0;
    }
    
    
    // 遷移
    
    // cout << "OK " << l << " " << unk << " " << nk << endl;

    //知っているものが出た場合
    if(nk > 0){
        dp[l][unk][nk] += ((double) nk / (double) unk) * (1 + getDp(l, unk - 1, nk -1));
        // cout << "update0: " << dp[l][unk][nk] << endl;
    }
     

    //知らないものが出た場合
   
    double notFoundP = (((double) (unk - nk) / (double) unk));
    
    // cout << "OK2: " << notFoundP << endl;
    if(notFoundP > 0){// 1つ目が違う...(l, unk - 1, nk + 1)
        // 2つ目が同じ
        dp[l][unk][nk] += notFoundP * ((double) 1 / (double) (unk - 1)) * (1 + getDp(l, unk - 2, nk));
        // 2つ目は知っているもの unk - 1, nk + 1の状態から
        if(nk > 0){
            if(l > 1){
                dp[l][unk][nk] += notFoundP * ((double) nk / (double) (unk - 1)) * (1 + getDp(l - 1, unk - 2, nk));
            }
            
        }

        // cout << "update1: " << dp[l][unk][nk] << endl;
        // 2つ目も知らない
        if(unk - nk > 2){
            dp[l][unk][nk] += notFoundP * (((double) (unk - nk - 2) / (double) (unk - 1))) * getDp(l - 1, unk - 2, nk + 2);
        }
        
        // cout << "update2: " << dp[l][unk][nk] << endl;
    }
    // cout << l << " " << unk << " " << nk << " " << dp[l][unk][nk] << endl;

    return dp[l][unk][nk];
    
    
    



}
int main(){
    ll N, L;
    cin >> N >> L;
    vl vecA(N);
    long double ave = 0;
    ll total = 0;
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
        total += vecA[i];
    }
    ave = (double) total / N;

    dp = vector<vector<vector<long double>>>(L + 1, vector<vector<long double>>(2 * N + 1, vector<long double>(2 * N + 1, 0)));
    done = vector<vector<vector<bool>>>(L + 1, vector<vector<bool>>(2 * N + 1, vector<bool>(2 * N + 1, false)));

    long double ans = 0;
    ans = ave * getDp(L, 2 * N, 0);
    cout << ans << endl;

    
}