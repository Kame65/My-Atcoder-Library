#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;




ll N, M;
vl vecA, vecB, vecC;
vector<vvl> edges;
vector<vvl> memo;

void search1(ll startV, ll nowV, ll beforeV, ll minV, ll cost){

    if(memo[startV][nowV][minV] >= 0 && memo[startV][nowV][minV] <= cost){
        // cout << "return" << endl;
        return;
    }
    // if(startV == 1){
    //     cout << "startV " << startV << ",nowV " << nowV << ",minV " << minV << ",cost " << cost << endl;
    // }
    // if(cost > 10) {
    //     return;
    // }
    // cout << memo[startV][nowV][minV] << endl;
    // cout << startV << ",now: " << nowV << ",cost: " << cost << ",minV: " << minV << endl;

    if(memo[startV][nowV][minV] < 0 || memo[startV][nowV][minV] > cost)
    memo[startV][nowV][minV] = cost;
    // cout << "update" << endl;

    ll nextMinV = minV;
    if(minV < nowV && nowV != startV){
        nextMinV = nowV;
    }
    // cout << "minOK" << endl;
    for(ll i = 0; i < edges[nowV].size(); i ++){
        ll nextV = edges[nowV][i][0];
        // cout << i << "nextV" << nextV << endl;
        ll nextCost = cost + edges[nowV][i][1];
        search1(startV, nextV, nowV, nextMinV, nextCost);
    }
    return;
}

int main(){
    cin >> N >> M;
    vecA = vl(M);
    vecB = vl(M); 
    vecC = vl(M);
    edges = vector<vvl>(N + 1);
    memo = vector<vvl>(N + 1, vvl(N + 1, vl(N + 1, -1)));
    for(ll i = 0; i < M; i ++){
        cin >> vecA[i] >> vecB[i] >> vecC[i];
        edges[vecA[i]].push_back({vecB[i], vecC[i]});
    }
    for(ll s = 1; s <= N; s ++){
        search1(s, s, s, 1, 0);
    }
    ll ans = 0;
    for(ll s = 1; s <= N; s++){
        for(ll t = 1; t <= N; t ++){
            ll before = memo[s][t][0];
            for(ll k = 1; k <= N; k ++){
                // cout << "before: " << s << ", " << t << ", " << k << ", " << memo[s][t][k] << endl;
                if(memo[s][t][k] < 0){
                    memo[s][t][k] = before;
                }
                if(before >= 0 && (memo[s][t][k] > before || memo[s][t][k] == 0)){
                    memo[s][t][k] = before;
                }
                if(s == t){
                    memo[s][t][k] = 0;
                }
                // cout <<"after : " << s << ", " << t << ", " << k << ", " << memo[s][t][k] << endl;
                if(memo[s][t][k] > 0){
                    ans += memo[s][t][k];
                }
                // ans += memo[s][t][k];
                before = memo[s][t][k];
            }
        }
    }
    cout << ans << endl;

    
}



