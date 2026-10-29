#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;


ll N, M, K;
vl vecA, vecB, vecC, vecV;
vector<vector<pair<ll, ll>>> edges;
vvl vecKDist;
vvl vecK;

struct Compare {
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) const {
        return a.second > b.second; // 優先順位の向きを定義
    }
};

void searchFrom(ll v, ll ki){
    // cout << "Search" << endl;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare>pQ;
    pQ.push(make_pair(v, 0));
    while(pQ.size() > 0){
        pair<ll, ll>pa = pQ.top();
        pQ.pop();
        ll nowV = pa.first;
        ll nowCost = pa.second;
        // cout << "OK1" << endl;
        if(vecKDist[ki][nowV] >= 0){
            continue;
        }
        // cout << "OK" << endl;
        vecKDist[ki][nowV] = nowCost;
        for(ll i = 0; i < edges[nowV].size(); i ++){
            // cout << "push" << endl;
            pQ.push(make_pair(edges[nowV][i].first, nowCost + edges[nowV][i].second));
        }
        // cout << "what" << endl;
    }
}
vvl dp;
ll bitDp(ll v, ll already){//vからのbitdp
    // cout << "search: " << v << endl;
    if(dp[v][already] >= 0){
        // cout << "dp[v][already]: " << v << ", " << bitset<8>(already).to_string() << ", " << dp[v][already] << endl;
        return dp[v][already];
    }
    if(already == 1){
        return 0;
    }
    // cout << "searching" << v << ", " << bitset<8>(already).to_string() << endl;
    ll minCost = 1e18;
    ll cost;
    bool noCase = true;
    for(ll i = 1; i <= K; i ++){
        // cout << "i = " << i << endl;
        if(i != v && already >> i & 1){
            cost = bitDp(i, already & ~(1 << v)) + vecK[i][v];
            noCase = false;
            if(cost < minCost){
                minCost = cost;
            }
        }
        
    }
    if(noCase){
        minCost = vecK[v][0];
    }
    dp[v][already] = minCost;
    // cout << "dp[v][already]: " << v << ", " << already << ", " << dp[v][already] << endl;
    return minCost;

}

int main(){
    cin >> N >> M >> K;

    vecV = vl(K + 1);
    vecV[0] = 1;
    for(ll i = 1; i <= K; i ++){
        cin >> vecV[i];
    }
    edges = vector<vector<pair<ll, ll>>>(N + 1);
    for(ll i = 0; i < M; i ++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
    vecKDist = vvl(K + 1, vl(N + 1, -1));
    for(ll ki = 0; ki <= K; ki ++){
        searchFrom(vecV[ki], ki);
    }

    vecK = vvl(K + 1, vl(K + 1, 0));
    for(ll i = 0; i <= K; i ++){
        for(ll j = 0; j <= K; j ++){
            vecK[i][j] = vecKDist[i][vecV[j]];
            // cout << vecV[i] << ", " << vecV[j] << ", " << vecK[i][j] << endl;
        }
    }

    vvl vecRes(K + 1, vl(2));//vecRes[v1][v2] = {v2, cost}

    dp = vvl(K + 1, vl(1e6, -1));
    dp[0][1] = 0;
    ll minCost = 1e18;
    for(ll i = 1; i <= K; i ++){
        ll all = (ll)pow(2, K + 1) - 1;
        ll cost;
        // cout << i << endl;
        cost = bitDp(i, all) + vecK[i][0];
        if(cost < minCost){
            minCost = cost;
        }
    }
    cout << minCost<< endl;
    

}