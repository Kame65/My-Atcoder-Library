#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
using ll = long long int;
using vl = vector<ll>;



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


ll mod = 998244353;
ll N, M;
vl vecU, vecV;
vl pow2s;

ll pow2mod(ll n){
    ll result = 1;
    for(ll i = 0; i < n; i ++){
        result *= 2;
        result %= mod;
        pow2s.push_back(result);
    }
    return result;
}

int main(){
    cin >> N >> M;
    pow2s.push_back(1);
    ll defaultCost = pow2mod(M + 1) - 2;
    vecU.resize(M + 1);
    vecV.resize(M + 1);
    dsu uf(N + 1);
    for(ll i = 1; i <= M; i ++){
        cin >> vecU[i] >> vecV[i];
    }
    ll cost = 0;
    ll mergeCnt = 0;
    for(ll i = M; i > 0; i --){
        ll u = vecU[i];
        ll v = vecV[i];

        if(!uf.same(u, v)){
            if(mergeCnt < N - 2){
                uf.merge(u, v);
                cost += pow2s[i];
                cost %= mod;
                mergeCnt ++;
            }
        }else{
            cost += pow2s[i];
            cost %= mod; 
        }
    }
    // cout << cost << endl;
    cout << (defaultCost + mod - cost) % mod << endl;

    
}