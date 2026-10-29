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
ll mod = 998244353;
void solve(){
    ll N;
    cin >> N;
    vl vecP(N);
    // ll minV = N, minI = 0;
    ll ans = 0;
    // cout << "!!" << endl;
    bool allOK = true;
    for(ll i = 0; i < N; i ++){
        cin >> vecP[i];
    }
    for(ll i = 0; i < N; i ++){
        if(vecP[i] == i + 1){
            // cout << vecP[i] << endl;
            ans += N - i - 1;
            ans %= mod;
            // cout << "a" << ans << endl;;
        }else{
            allOK = false;
            break;
        }
        
    }
    if(allOK){
        ans += N;
        ans %= mod;
    }
    cout << ans << endl;
}


int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solve();
    }
}