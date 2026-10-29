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

void makeAll(ll N){
    
}

int main(){
    ll N;
    cin >> N;
    vl vecP(N), vecQ(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecP[i];
    }
    for(ll i = 0; i < N; i ++){
        cin >> vecQ[i];
    }
    vl factol(N + 1, 1);
    for(ll i = 1; i <= N; i ++){
        factol[i] = factol[i - 1] * i;
    }
    vl vecUsedA(N + 1, false), vecUsedB(N + 1, false);
    ll small = 0;
    ll large = 0;
    for(ll i = 0; i < N; i ++){
        ll remainA = 0;
        for(ll j = 1; j < vecP[i]; j ++){
            if(!vecUsedA[j]){
                remainA ++;
            }
        }
        vecUsedA[vecP[i]] = true;
        small += remainA * factol[N - i - 1];

        ll remainB = 0;
        for(ll j = 1; j < vecQ[i]; j ++){
            if(!vecUsedB[j]){
                remainB ++;
            }
        }
        vecUsedB[vecQ[i]] = true;
        large += remainB * factol[N - i - 1];
        
    }
    ll ans = large - small - 1;
    if(ans < 0){
        ans = 0;
    }
    // cout << large << endl;
    cout << ans << endl;
    
}