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
    ll N, D;
    cin >> N >> D;
    vl vecT = vl((ll)1e6 + 10, 0);
    // vl vecT = vl(20, 0);
    for(ll i = 0; i < N; i ++){
        ll s, t;
        cin >> s >> t;
        if(t - s >= D){
            vecT[s] ++;
            vecT[t - D + 1] --;
        }
    }

    for(ll i = 1; i < vecT.size(); i ++){
        vecT[i] = vecT[i - 1] + vecT[i];
        // cout << i << ", " << vecT[i] << endl;
    }
    ll ans = 0;
    for(ll i = 0; i < vecT.size(); i ++){
        ans += vecT[i] * (vecT[i] - 1) / 2;
    }
    cout << ans << endl;
    
}