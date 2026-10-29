#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll N, M, S, T; cin >> N >> M >> S >> T;
    vvl edges(N + 1);
    for(ll i = 0; i < M; i ++){
        ll a, b; cin >> a >> b;
        edges[a].push_back(b);
    }
    for(ll i = 1; i <= N; i ++){
        sort(edges[i].begin(), edges[i].end());
    }

    vl result(N + 1, -1);

    deque<vector<ll>> q;
    q.push_back({S, 0});
    while(q.size() > 0){
        auto info = q.front();
        q.pop_front();
        ll nv = info[0];
        ll cost = info[1];
        // cout << nv << endl;
        if(result[nv] >= 0)continue;
        result[nv] = cost;
        for(int i = 0; i < edges[nv].size(); i ++){
            ll av = edges[nv][i];
            // cout << "av: " << av << endl;
            if(i == 0) q.push_front({av, cost});
            else q.push_back({av, cost + 1});
        }
    }
    // for(int i = 1; i <= N; i ++){
    //     cout << result[i] << " ";
    // }
    // cout << endl;
    cout << result[T] << endl;

}