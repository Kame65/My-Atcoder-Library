#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;
using vl = vector<ll>;

ll N, M;
ll mod;
vl lastFirst, lastOther;
ll getLastOther(ll);
ll getLastFirst(ll n){//1から始まり1で終わる数
    
    if(lastFirst[n] >= 0){
        return lastFirst[n];
    }
    // cout << "getLastFirst: " << n << endl;
    if(n == 1){
        lastFirst[n] = 1;
        return 1;
    }
    lastFirst[n] = getLastOther(n - 1);
    return lastFirst[n];

}
ll getLastOther(ll n){
    
    if(lastOther[n] >= 0){
        return lastOther[n];
    }
    // cout << "getLastOther" << n << endl;
    if(n == 1){
        lastOther[n] = 0;
        return 0;
    }
    lastOther[n] = ((mod + (getLastOther(n - 1) * (M - 2)) % mod + ((getLastFirst(n - 1)) * (M - 1)) % mod) % mod);
    return lastOther[n];

}

int main(){
    mod = 998244353;
    cin >> N >> M; 
    ll ans;
    lastOther = vl(N + 1, -1);
    lastFirst = vl(N + 1, -1);
    ans = getLastOther(N) * M % mod;
    cout << ans << endl;
    // cout << getLastFirst(N) << endl;
    // cout << getLastOther(N) << endl;
    
}