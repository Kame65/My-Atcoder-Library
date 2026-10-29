#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;

ll N, W;
vl vecA, vecB;
ll findMax(ll idx, ll tA, ll tB){
    if(tB > W) return -1;
    if(idx == N) return tA;
    ll v1 = findMax(idx + 1, tA + vecA[idx], tB + vecB[idx]);
    ll v2 = findMax(idx + 1, tA, tB);
    ll result = max(v1, v2);
    return max(result, tA);
}

int main(){
    cin >> N >> W;
    vecA = vl(N);
    vecB = vl(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i] >> vecB[i];
    }
    ll ans = findMax(0, 0, 0);
    cout << ans << endl;
}