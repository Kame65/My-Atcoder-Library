#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <assert.h>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;
using vb = vector<bool>;
struct dsu {
   public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

   private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};
ll N, M;

vvl edges, inverseEdges;
vector<pair<ll, ll>> searched;
vb searching;
dsu uf;

ll SCC1(ll v, ll cnt){//searched[v] = 0 -> 未調査, startV -> 調査中, N+startV->閉路あり, -1閉路なし
    if(searching[v]){
        return cnt;
    }
    searching[v] = true;
    
    for(ll i = 0; i < edges[v].size(); i ++){
        ll nextV = edges[v][i];
        cnt = SCC1(nextV, cnt);
        // cout << cnt << endl;
    }
    searched[v].first = cnt;
    searched[v].second = v;
    // cout << "v: " << v << "cnt: " << cnt << endl;
    return cnt + 1;
}
void SCC2(ll v, ll beforeV){//searched[v] = 0 -> 未調査, startV -> 調査中, N+startV->閉路あり, -1閉路なし
    
    if(searching[v]){
        return;
    }
    
    // cout << "nowV = " << v << endl;
    searching[v] = true;
    if(!uf.same(v, beforeV) && beforeV != 0){
        uf.merge(v, beforeV);
    }
    
    for(ll i = 0; i < inverseEdges[v].size(); i ++){
        ll nextV = inverseEdges[v][i];

        
        SCC2(nextV, v);
    }

    return;
}

int main(){
    cin >> N >> M;
    edges = vvl(N + 1);
    inverseEdges = vvl(N + 1);
    searching = vb(N + 1, false);
    searched = vector<pair<ll, ll>>(N + 1, pair<ll, ll>(0, 0));

    for(ll i = 0; i < M; i ++){
        ll a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        inverseEdges[b].push_back(a);
    }
    ll cnt = 1;
    for(ll i = 1; i <= N; i ++){
        cnt = SCC1(i, cnt);
    }
    sort(searched.begin(), searched.end());
    // cout << "sorted" << endl;
    uf = dsu(N + 1);
    searching = vb(N + 1, false);
    for(ll i = N; i > 0; i --){
        // cout << searched[i].first << ", " << searched[i].second << endl;
        SCC2(searched[i].second, 0);
    }
    // cout << "SCC2End" << endl;
    ll ans = 0;
    vector<vector<int>> groups = uf.groups();
    for(ll i = 0; i < groups.size(); i ++){
        ll size = groups[i].size();
        if(size > 1){
            // cout << "size: " << size << endl;
            // for(ll j = 0; j < size; j ++){
            //     cout << groups[i][j] << " ";
            // }
            // cout << endl;
            ans += size * (size - 1) / 2;
        }
    }
    cout << ans << endl;
    

    
}