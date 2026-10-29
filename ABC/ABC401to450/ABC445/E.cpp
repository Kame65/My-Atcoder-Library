#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <numeric> 
using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;




void solve(){
    ll N;
    cin >> N;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll gcdMax = 1;
    for(ll i = 0; i < N; i ++){
        gcdMax *= (vecA[i] / gcd(gcdMax, vecA[i]));
    }
    for(ll i = 0; i < )
}


int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solve();
    }
}