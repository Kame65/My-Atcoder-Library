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


ll N, M;


int main(){
    cin >> N >> M;
    vl memoStart(N + 1, -1);
    vector<vector<pair<ll, ll>>> edges(N + 1);
    for(ll i = 0; i < M; i ++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(-c, b));
        edges[b].push_back(make_pair(-c, a));

    }
    priority_queue<pair<ll, ll>> pq;
    pq.push(make_pair(0, 1));
    
    while(pq.size() > 0){
        ll nowCost, v;
        tie(nowCost, v) = pq.top();
        pq.pop();
        if(memoStart[v] < 0){
            memoStart[v] = -nowCost;
            for(ll i = 0; i < edges[v].size(); i ++){
                ll nextC, nextV;
                tie(nextC, nextV) = edges[v][i];
                pq.push(make_pair(nowCost + nextC, nextV));
            }
        }
    }

    vl memoEnd(N + 1, -1);
    pq.push(make_pair(0, N));
    while(pq.size() > 0){
        ll nowCost, v;
        tie(nowCost, v) = pq.top();
        pq.pop();
        if(memoEnd[v] < 0){
            memoEnd[v] = -nowCost;
            for(ll i = 0; i < edges[v].size(); i ++){
                ll nextC, nextV;
                tie(nextC, nextV) = edges[v][i];
                pq.push(make_pair(nowCost + nextC, nextV));
            }
        }
    }
    
    for(ll i = 1; i <= N; i ++){
        cout << memoStart[i] + memoEnd[i] << endl;
    }
}