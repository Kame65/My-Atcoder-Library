#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

ll N, M;
vl vecA, maxA;
vector<vector<pair<ll, ll>>> edges;

struct Compare{
    bool operator()(pair<ll, ll>&alpha, pair<ll, ll>&beta){
        return alpha.second > beta.second;
    }
};


int main(){
    cin >> N >> M;
    vecA = vl(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    edges = vector<vector<pair<ll, ll>>>(N + 1);
    for(ll i = 0; i < M; i ++){
        ll u, v;
        cin >> u >> v;
        edges[u].push_back(make_pair(v, vecA[v]));
        edges[v].push_back(make_pair(u, vecA[u]));

    }

    // vecA[v]の昇順に並べ替え
    for(ll i = 1; i <= N; i ++){
        sort(edges[i].begin(),edges[i].end(),[](const pair<ll, ll> &alpha,const pair<ll, ll> &beta){return alpha.second < beta.second;});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> qu; 
    qu.push(make_pair(1, vecA[1]));

    maxA = vl(N + 1, -1);
    maxA[1] = 1;
    vector<bool> judged(N + 1, false);
    while(qu.size() > 0){
        ll v, val;
        tie(v, val) = qu.top();

        // cout << "tie: " << v << " " << val << endl;
        qu.pop();
        if(judged[v]){
            continue;
        }
        judged[v] = true;
        for(ll i = 0; i < edges[v].size(); i ++){
            ll nextV, nextVal;
            tie(nextV, nextVal) = edges[v][i];
            if(nextVal < val){
                continue;
            }
            if(maxA[nextV] >= 0 && maxA[nextV] > maxA[v]){
                continue;
            }
            cout << v << " -> " << nextV << endl;
            qu.push(edges[v][i]);
            if(nextVal == val){
                maxA[nextV] = maxA[v];
            }else{
                maxA[nextV] = maxA[v] + 1;
            }
            

        }

    }
    cout << "result: " << endl;
    for(ll i = 1; i <= N; i ++){
        cout << maxA[i] << endl;
    }
    cout << endl;

    if(maxA[N] < 0){
        cout << 0 << endl;
    }else{
        cout << maxA[N] << endl;
    }
    

}