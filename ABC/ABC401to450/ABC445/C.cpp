#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

vl dp;
vl vecA;


ll getDp(ll n){
    if(dp[n] > 0){
        return dp[n];
    }
    if(n == vecA[n]){
        dp[n] = n;
        return n;
    }
    else{
        dp[n] = getDp(vecA[n]);
        return dp[n];
    }
}
int main(){
    ll N;
    cin >> N;
    vecA.resize(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    dp.resize(N + 1, -1);
    for(ll i = 1; i <= N; i ++){
        cout << getDp(i) << " ";
    }
    
}

