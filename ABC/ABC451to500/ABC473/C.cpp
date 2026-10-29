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
    ll N, K;
    cin >> N >> K;
    vl vecC(K + 1, 0);
    for(ll i = 0; i < N; i ++){
        ll a;
        cin >> a;
        vecC[a] ++;
    }

    ll max = *max_element(vecC.begin(), vecC.end());
    ll ans = 0;
    for(ll i = 1; i < K + 1; i ++){
        if(vecC[i] >= max - 1){
            ans ++;
        }
    }
    cout << ans << endl;
    
}
