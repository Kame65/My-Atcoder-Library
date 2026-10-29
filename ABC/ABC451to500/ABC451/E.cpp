#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <assert.h>


using namespace std;
using ll = long long int;

vector<vector<vector<ll>>> edges;

vector<vector<ll>> beforeEdges, sortEdges;



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


bool judge(ll beforeV, ll v, ll firstV, ll totalCost){
    for(ll i = 0; i < edges[v].size(); i ++){
        ll nextV = edges[v][i][0];
        ll cost = edges[v][i][1];
        if(nextV != beforeV){

            ll largerV = nextV;
            ll startV = firstV;

            if(nextV < firstV){
                largerV = firstV;
                startV = nextV;
            }

            if(beforeEdges[startV][largerV] != totalCost + cost){
                // cout << firstV << ", " << largerV << ", " << totalCost + cost << endl;
                return false;
            }

            
            if(!judge(v, nextV, firstV, totalCost + cost)){
                return false;
            }

        }
    }
    return true;
}

ll N;

int main(){

    cin >> N;
    edges.resize(N + 1);
    beforeEdges.resize(N + 1);
    for(ll i = 0; i < N + 1; i ++){
        beforeEdges[i].resize(N + 1);
    }
    for(ll i = 1; i <= (N - 1); i ++){
        for(ll j = i + 1; j <= N; j ++){
            ll a;
            cin >> a;
            vector<ll> vecA = {i, j, a};
            sortEdges.push_back(vecA);
            beforeEdges[i][j] = a;

        }
    }

    sort(sortEdges.begin(),sortEdges.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[2] < beta[2];});

    dsu uf(N + 1);
    for(ll i = 0; i < sortEdges.size(); i ++){
        ll v1 = sortEdges[i][0];
        ll v2 = sortEdges[i][1];
        ll cost = sortEdges[i][2];
        // cout << v1 << ", " << v2 << endl;
        if(!uf.same(v1, v2)){
            uf.merge(v1, v2);
            vector<ll> info = {v2, cost};
            edges[v1].push_back(info);
            info = {v1, cost};
            edges[v2].push_back(info);
        }
    }
    bool result = true;

    // cout << "Judge!" << endl;
    for(ll v = 1; v <= N; v ++){
        if(!judge(0, v, v, 0)){
            result = false;
        }
    }
    if(result){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



}