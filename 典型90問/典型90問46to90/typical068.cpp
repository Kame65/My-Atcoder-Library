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


int main(){
    ll N, Q;
    cin >> N >> Q;

    vl sum(N + 1);
    for(ll i = 0; i < Q; i ++){
        ll t, x, y, v;
        cin >> t >> x >> y >> v;
        sum[x] = y;
    }
}