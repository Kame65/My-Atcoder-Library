#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

vvl vecC;
vvl dp;

ll getDp(ll first, ll n){
    if(dp[first][n] > 0){
        return dp[first][n];
    }
    ll minCost = vecC[first][n];
    for(ll i = first + 1; i < n; i ++){
        ll cost = getDp(first, i) + vecC[i][n];
        if(cost < minCost){
            minCost = cost;
        }
    }
    dp[first][n] = minCost;
    return minCost;
}

int main(){
    ll N;
    cin >> N;
    dp.resize(N + 1);
    for(ll i = 0; i <= N; i ++){
        dp[i].resize(N + 1, -1);
    }

    vecC.resize(N + 1);
    vecC[N].resize(N + 1);
    
    for(ll i = 1; i < N; i ++){
        vecC[i].resize(N + 1);
        
        for(ll j = i + 1; j <= N; j ++){
            cin >> vecC[i][j];
        }
    }
    // cout << "OK" << endl;
    for(ll first = 1; first < N; first ++){
        getDp(first, N);
    }
    bool result = true;
    for(ll i = 1; i < N; i ++){
        for(ll j = i + 1; j <= N; j ++){
            if(dp[i][j] != vecC[i][j]){
                result = false;
            }
        }
    }
    if(result){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    

}