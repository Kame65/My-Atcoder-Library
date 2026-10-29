#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


ll N;
vvl edges;
vl used;
vl unused;
vl results;

ll getUnused(ll, ll);

ll getUsed(ll n, ll before){//nを使った時の最大数を返す
    if(used[n] >= 0){
        return used[n];
    }
    if(edges[n].size() == 1 && before != -1){
        used[n] = 1;
        return 1;
    }
    ll total = 1;
    for(ll i = 0; i < edges[n].size(); i ++){
        ll nextV = edges[n][i];
        if(nextV != before){
            total += getUnused(nextV, n);
        }
    }
    used[n] = total;
    return total;

}
ll getUnused(ll n, ll before){
    if(unused[n] >= 0){
        return unused[n];
    }
    if(edges[n].size() == 1 && before != -1){
        unused[n] = 0;
        return 0;
    }
    ll total = 0;
    for(ll i = 0; i < edges[n].size(); i ++){
        ll nextV = edges[n][i];
        if(nextV != before){
            total += max(getUsed(nextV, n), getUnused(nextV, n));
        }
    }
    unused[n] = total;
    return total;
}

void getRoute(ll n, ll before, bool useN){
    if(useN){
        results[n] = true;
    }
        for(ll i = 0; i < edges[n].size(); i ++){
        ll nextV = edges[n][i];
        if(nextV != before){
            if(useN || unused[nextV] > used[nextV]){
                getRoute(nextV, n, false);
            }else{
                getRoute(nextV, n, true);
            }
        }
    }
}


int main(){
    cin >> N;
    edges.resize(N + 1, vl());
    used.resize(N + 1, -1);
    unused.resize(N + 1, -1);
    results.resize(N + 1, false);
    for(ll i = 0; i < N - 1; i ++){
        ll a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    edges[0].push_back(1);
    edges[1].push_back(0);
    getUnused(0, -1);
    cout << "debag: " << getUnused(2, 1) << endl;
    getRoute(0, -1, false);
    ll cnt = 0;
    for(ll i = 1; i <= N; i ++){
        // cout << results[i] << endl;
        if(results[i]){
            cnt ++;
            cout << i << " ";
        }
        if(cnt == N / 2){
            break;
        }
    }
    cout << endl;

}