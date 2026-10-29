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
    ll mod = 1e9 + 7;
    ll N;
    ll ans = 1;
    cin >> N;
    for(ll i = 0; i < N; i ++){
        ll rowTotal = 0;
        for(ll j = 0; j < 6; j ++){
            ll a;
            cin >> a;
            rowTotal += a;
        }
        ans *= rowTotal;
        ans %= mod;
    }
    cout << ans << endl;

}