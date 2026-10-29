#include <iostream>

using ll = long long int;
using namespace std;

ll mod = 1e9 + 7;
ll powMod(ll p, ll n, ll mod){//return (p^n)%mod O(log(n))
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
    cout << powMod(4, 3, mod) << endl;
}