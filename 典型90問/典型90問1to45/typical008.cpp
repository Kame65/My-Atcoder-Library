#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


ll N;
ll mod = 1e9 + 7;
string S;
vector<vector<ll>>dp;
vector<ll> idxToChar = {'0', 'a', 't', 'c', 'o', 'd', 'e', 'r'};

ll getDp(ll n, ll k){// idx = nかつk文字目 atcoder
    if(n == 0){
        // cout << "n = 0" << endl;
        return 0;
    }
    if(dp[n][k] > 0){
        return dp[n][k];
    }
    if(S[n - 1] == 'a' && idxToChar[k] == S[n - 1]){
        // cout << "Abegin" << endl;
        dp[n][k] = (getDp(n - 1, k) + 1) % mod;
        // cout << "Aend " << endl;
    }
    else if(S[n - 1] == idxToChar[k]){
        dp[n][k] = (getDp(n - 1, k - 1) + getDp(n - 1, k)) % mod;
    }else{
        dp[n][k] = (getDp(n - 1, k)) % mod;
    }
    // cout << n << ", " << k << ", " << S[n-1] << ", " << dp[n][k] << endl;
    return dp[n][k];
}
int main(){
    cin >> N >> S;
    dp.resize(N + 1, vector<ll>(8, -1));

    cout << getDp(N, 7) << endl;  



    



}