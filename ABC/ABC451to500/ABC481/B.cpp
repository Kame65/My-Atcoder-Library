#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N, K; cin >> N >> K;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll ans = 0;
    if(vecA[0] == K) ans ++;
    for(ll i = 1; i < N; i ++){
        if((vecA[i] - K) * (vecA[i - 1] - K) < 0){
            ans ++;
        }else{
            if(vecA[i] == K) ans ++;
        }
    }
    cout << ans << endl;
}