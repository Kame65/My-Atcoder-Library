#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;


ll N, K, D;
vl vecA;
vector<vvl> dp;

ll getDp(ll n, ll k, ll d){
    // cout << "getDp: " << n << ", " << k << ", " << d << endl;
    if(dp[n][k][d] != -2){
        return dp[n][k][d];
    }
    // cout << "!-2" << endl;
    if(k == 0 && d == 0){
        // cout << "0: " << n << ", " << k << ", " << d << endl;
        dp[n][k][d] = 0;
        return 0;
    }
    if(n < k || k == 0){
        dp[n][k][d] = -1;
        return -1;
    }
    
    // if(n == k){
    //     ll result = 0;
    //     for(ll i = 0; i < n; i ++){
    //         result += vecA[i];
    //     }
        
    //     if(result % D == d){
    //         // cout << "sum" << endl;
    //         dp[n][k][d] = result;
    //         return result;
            
    //     }else{
    //         // cout << "-1!!" << endl;
    //         dp[n][k][d] = -1;
    //         return -1;
    //     }
        
    // }
    ll result1 = getDp(n - 1, k - 1, (D + d - (vecA[n] % D)) % D);
    ll result2 = getDp(n - 1, k, d);
    if(result1 != -1){
        result1 += vecA[n];
    }
    ll result = max(result1, result2);
    dp[n][k][d] = result;
    // cout << "result: " << n << ", " << k << ", " << d << ", " << result << endl;
    return result;
}

int main(){
    cin >> N >> K >> D;
    vecA = vl(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    dp = vector<vvl>(N + 1, vvl(K + 1, vl(D, -2)));
    dp[1][1] = vl(D, -1);
    dp[1][1][vecA[1] % D]  = vecA[1];

    cout << getDp(N, K, 0) << endl;



}