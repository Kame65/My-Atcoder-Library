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


vvl convs;
ll conv(ll n, ll p){
    if(convs[n][p] > 0){
        return convs[n][p];
    }
    ll res = 1;
    for(int i = 0; i < p; i ++){
        res *= n;
        
    }
    
    
}

int main(){
    
    ll X1, X2, X3;
    cin >> X1 >>X2 >> X3;
    ll size = X1 + X2 + X3;
    convs = vvl(size, vl(size));

    
    ll ans = 1;
    ll X1cnt = 1, X2cnt = 1, X3cnt = 1;
    ll noConerTotal = 0;
    ll oneConerTotal = 0;
    for(ll i = 1; i <= X3; i ++){
        ll noConerOne = conv(X1 + i - 2, i) - noConerTotal;
        noConerTotal += conv(X1 + i - 2, i);
        ans += (conv(X1 + i - 2, i) - noConerTotal) * (conv(X1 + i + 1 - 2 * i,X2 - 2 * i));
        noConerTotal += conv(X1 + i - 2, i);
    }
    cout << X1cnt << " " << X2cnt << " " << X3cnt << endl;
    cout << ans << endl;
}