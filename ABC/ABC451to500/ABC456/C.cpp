#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <assert.h>
#include <set>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;
ll mod = 998244353;

string S;
int main(){
    cin >> S;
    ll ans = S.size();
    char before = '0';
    ll cnt = 0;
    for(ll i = 0; i < S.size(); i ++){
        // cnt ++;
        if(before == S[i]){
            if(cnt >= 2){
                ans += cnt * (cnt - 1) / 2;
                // cout << cnt << endl;
            }
            cnt = 1;
        }else{
            cnt ++;
        }
        before = S[i];
        ans %= mod;
    }
    if(cnt >= 2){
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans % mod << endl;
}