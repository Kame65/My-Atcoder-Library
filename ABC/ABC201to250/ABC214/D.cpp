#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


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




int main(){
    ll N;
    cin >> N;
    vvl vecE(N - 1);
    for(ll i = 0; i < N - 1; i ++){
        ll u, v, w;
        cin >> u >> v >> w;
        vecE[i] = {u, v, w};
    }
    sort(vecE.begin(), vecE.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[2] < beta[2];});
    dsu uf(N + 1);
    ll ans = 0;
    for(ll i = 0; i < N - 1; i ++){
        ll u, v, w;
        u = vecE[i][0], v = vecE[i][1], w = vecE[i][2];
        ll size1 = uf.size(u);
        ll size2 = uf.size(v);
        ans += size1 * size2 * w;
        uf.merge(u, v);

    }
    cout << ans << endl;
    
    


}