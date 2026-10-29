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
    ll N, V;
    cin >> N >> V;
    vl vecW(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecW[i];
    }
    ll ans = 0;
    for(ll c1 = 0; c1 < N - 2; c1 ++){
        for(ll c2 = c1 + 1; c2 < N - 1; c2 ++){
            for(ll c3 = c2 + 1; c3 < N; c3 ++){
                if(c1 + c2 + c3 + 3 > V){
                    break;
                }
                ll val = vecW[c1] + vecW[c2] + vecW[c3];
                if(val > ans){
                    ans = val;
                }
            }
        }
    }
    cout << ans << endl;


}
