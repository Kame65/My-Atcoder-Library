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
vl facs;
ll getFacs(ll n){

}

ll mod = 998244353;

int main(){
    
    ll N, M;
    cin >> N >> M;
    
    string S;
    cin >> S;
    dsu uf(N);
    facs = 
    for(ll i = 0; i < M; i ++){
        ll a, b;
        cin >> a >> b;
        a --; b--;
        if(!uf.same(a, b)){
            uf.merge(a, b);
        }
    }
    bool in2 = false;

    vector<vector<int>>groups = uf.groups();
    for(vector<int> g: groups){
        unordered_map<char, bool> map;
        for(ll idx: g){
            if(map[S[idx]]){
                in2 = true;
            }
            map[S[idx]] = true;
        }
    }
    
    ll ans = 1;

    for(ll i = 0; i < groups.size(); i ++){
        cout << "groups" << i << " " << groups[i].size() << endl;
        unordered_map<char, int> map;
        for(ll j = 1; j <= groups[i].size(); j ++){
            ans *= j;
            ans %= mod;
        }
    }
    if(!in2){
        cout << "!in2" << endl;
        ans /= 2;
    }
    cout << ans << endl;

    

}