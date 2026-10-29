#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

ll mod = 1e9 + 7;
ll powMod(ll p, ll n, ll mod){//return p^n
    ll result = 1;
    ll x = p;
    while(n > 0){
        if(n % 2 == 1){
            result *= x;
            result %= mod;
        }
        x = (x * x) % mod;
        n /= 2;
        
    }
    return result; 
}

int main(){
    ll N, K;
    cin >> N >> K;
    ll ans = K;
    if(N > 1){
        ans *= K - 1;
        ans %= mod;
        ans *= powMod(K - 2, N - 2, mod);
    }
    cout << ans % mod << endl;
    

}