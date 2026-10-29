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


// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する log(p)
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}

void culcCum(vl& vecA, vl& cum){
    cum[0] = 0;
    for(ll i = 0; i < vecA.size(); i ++){
        cum[i + 1] = cum[i] + vecA[i];
    }
    
}

int main(){
    ll N;
    ll mod = 998244353;
    cin >> N;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    vl cum(N + 1);
    culcCum(vecA, cum);
    ll ans = 0;
    ll inverse = modinv(N, mod);
    for(ll i = 0; i < (N + 2) / 2; i ++){

        ll oneCulc = cum[N] - cum [0];
        oneCulc %= mod;

        for(ll k = i; k < i + 1; k ++){
            
            ans += cum[j - k] - cum[i + k];
            ans %= mod;
            // ans *= modinv(N - (2 * k), mod);
            ans %= mod;
        }
        oneCulc *= modinv(N, mod);
        ans += oneCulc;
    }

    cout << ans << endl;


    
}