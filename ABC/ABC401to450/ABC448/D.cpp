#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
using ll = long long int;


ll N;
vector<ll>vecA;
vector<vector<ll>>edge;
unordered_map<ll, ll>memo;
vector<bool> result;


void search(ll nowP, ll before){
    // cout << before << " -> " << nowP << endl;
    memo[vecA[nowP]] += 1;
    if(result[before]){
        result[nowP] = true;
    }
    else if(memo[vecA[nowP]] >= 2){
        result[nowP] = true;
    }
    // cout << "OK" << endl;
    for(ll i = 0; i < edge[nowP].size(); i ++){
        if(edge[nowP][i] != before){
            search(edge[nowP][i], nowP);
        }
    }
    memo[vecA[nowP]] -= 1;
}
int main(){
    cin >> N;
    vecA.resize(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    edge.resize(N + 1);
    for(ll i = 0; i < N - 1; i ++){
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    result.resize(N + 1);
    search(1, 0);

    for(ll i = 1; i <= N; i ++){
        if(result[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
}