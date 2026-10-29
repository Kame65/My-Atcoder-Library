#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <assert.h>
using namespace std;
using ll = long long int;


struct dsu {
   public:
    dsu() : _n(0) {}
    dsu(ll n) : _n(n), parent_or_size(n, -1) {}

    ll merge(ll a, ll b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        ll x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(ll a, ll b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    ll leader(ll a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    ll size(ll a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<ll>> groups() {
        std::vector<ll> leader_buf(_n), group_size(_n);
        for (ll i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<ll>> result(_n);
        for (ll i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (ll i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<ll>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

   private:
    ll _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<ll> parent_or_size;
};


ll N;
vector<ll> listL, listR;
int main(){
    listL.resize(N);
    listR.resize(N);
    
}