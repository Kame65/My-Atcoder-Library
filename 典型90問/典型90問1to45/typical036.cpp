#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <functional>
#include <string>
#include <set>
#include <math.h>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;
using vb = vector<bool>;


int main(){
    ll N, Q;
    cin >> N >> Q;
    vl vecX(N), vecY(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecX[i] >> vecY[i];
    }

    ll p0X = -1e9;
    ll p0Y = -1e9;
    ll p1X = -1e9;
    ll p1Y = 1e9;
    ll p0Min = 2e9, p0Max = 0;
    ll p1Min = 2e9, p1Max = 0;
    vl vecQ(Q);
    for(ll i = 0; i < Q; i ++){
        cin >> vecQ[i];
    }
    
    for(ll i = 0; i < N; i ++){
        ll dis0 = abs(p0X - vecX[i]) + abs(p0Y - vecY[i]);
        if(dis0 < p0Min) p0Min = dis0;
        if(dis0 > p0Max) p0Max = dis0;
        ll dis1 = abs(p1X - vecX[i]) + abs(p1Y - vecY[i]);
        if(dis1 < p1Min) p1Min = dis1;
        if(dis1 > p1Max) p1Max = dis1;
    }

    for(ll i = 0; i < Q; i ++){
        ll idx = vecQ[i] - 1;
        ll dis0 = abs(p0X - vecX[idx]) + abs(p0Y - vecY[idx]);
        ll dis1 = abs(p1X - vecX[idx]) + abs(p1Y - vecY[idx]);

        ll max0 = max(abs(dis0 - p0Min), abs(dis0 - p0Max));
        ll max1 = max(abs(dis1 - p1Min), abs(dis1 - p1Max));
        ll ans = max(max0, max1);
        cout << ans << endl;
    }


}

