#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using ll = long long int;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


ll N, M;
vl vecA, vecB;
vector<bool> results;
vvl edges;
void search(ll n){
    if(results[n]){
        return;
    }
    results[n] = true;
    for(ll i = 0; i < edges[n].size(); i ++){
        search(edges[n][i]);
    }
}
int main(){
    cin >> N >> M;
    edges = vvl(N + 1);
    results = vector<bool>(N, false);
    for(ll i = 0; i < M; i ++){
        ll a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        
    }
    search(1);
    ll ans = 0;
    for(ll i = 1; i <= N; i ++){
        if(results[i]){
            ans ++;
        }
    }
    cout << ans << endl;
}