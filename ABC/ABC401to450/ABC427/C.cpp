#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
using ll = long long int;



ll N, M;
vector<vector<int>> edges;
vector<int> group, results;

vector<int> black, white;

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

void judge(){
    // cout << group[1] << group[2] << group[3] << endl; 
    black.clear();
    white.clear();
    for(int i = 1; i <= N; i ++){
        if(group[i] == 1){
            black.push_back(i);
        }else{
            white.push_back(i);
        }
    }

    dsu uf = dsu(N + 1);//0が孤立に気をつける
    dsu lastUf = dsu(N + 1);
    for(size_t i = 1; i < black.size(); i ++){
        if(!uf.same(black[i - 1],black[i])){
            uf.merge(black[i - 1],black[i]);
        }
    }
    // cout << "whiteSize" << white.size() << endl;
    for(size_t i = 1; i < white.size(); i ++){
        // cout << white[i] << " " << endl;// << white[i + 1];
        if(!uf.same(white[i - 1], white[i])){
            // cout << white[i] << " " << white[i + 1];
            uf.merge(white[i - 1], white[i]);
        }
    }
    // cout << "Why" << endl;
    int result = 0;
    for(int i = 1; i <= N; i ++){
        for(size_t j = 0; j < edges[i].size(); j ++){
            if(uf.same(i, edges[i][j])){
                result += 1;
            }else{
                lastUf.merge(i, edges[i][j]);
            }
        }
    }//削除処理完了

    results.push_back(result);
    return;
}

void solve(int idx){
    if(idx > N){
        judge();
        return;
    }
    else{
        group[idx] = 1;
        solve(idx + 1);
        group[idx]  = -1;
        solve(idx + 1);
    }
    return;

}
int main(){
    cin >> N >> M;
    edges.resize(N + 1);
    group.resize(N + 1);
    for(int i = 0; i < M; i ++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    solve(1);
    int min = 10000;
    for(size_t i = 0; i < results.size(); i ++){
        if(min > results[i]){
            min = results[i];
        }
    }
    cout << min << endl;

    

}