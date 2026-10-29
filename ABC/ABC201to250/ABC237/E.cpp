#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, M;
    cin >> N >> M;
    vl vecH(N + 1);
    for(int i = 1; i <= N; i ++){
        cin >> vecH[i];
    }
    vvl edges(N + 1, vl());
    for(int i = 0; i < M; i ++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    priority_queue<pair<ll, ll>>search; // {cost, nowV};
    vl memo(N + 1, LLONG_MIN);
    search.push(make_pair(0, 1));
    while(search.size() > 0){
        auto info = search.top();
        search.pop();
        auto cost = info.first;
        auto nV = info.second;
        cerr << "cost: " << cost << " nV: " << nV << endl;
        if(memo[nV] >= cost) continue;
        memo[nV] = cost;
        for(ll aV: edges[nV]){
            if(vecH[aV] > vecH[nV]){//高い所に行く
                search.push(make_pair(cost + vecH[nV] - vecH[aV], aV));
            }else{
                search.push(make_pair(cost, aV));
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i ++){
        cerr << memo[i] << " ";
        if(memo[i] + vecH[1] - vecH[i] > ans) ans = memo[i] + vecH[1] - vecH[i];
    }
    cerr << endl;
    cout << ans << endl;

}