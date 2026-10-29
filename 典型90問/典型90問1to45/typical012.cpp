#include<assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


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



ll H, W, Q;
vector<ll> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
vector<vector<bool>> field;
int main(){
    cin >> H >> W >> Q;
    dsu uf((H + 1) * (W + 1) + 1);
    field = vector<vector<bool>>(H + 2, vector<bool>(W + 2, false));
    for(ll i = 0; i < Q; i ++){
        ll q;
        cin >> q;
        // cout << q << " : " << i  << endl;
        if(q == 1){
            ll r, c;
            cin >> r >> c;
            field[r][c] = true;
            for(ll i = 0; i < 4; i ++){
                ll x = c + dx[i];
                ll y = r + dy[i];
                if(field[y][x]){
                    if(!uf.same(y * (W + 1) + x, r * (W + 1) + c)){
                        uf.merge(y * (W + 1) + x, r * (W + 1) + c);
                        // cout << "merge : " << x << ", " << y  << ", " << r << ", " << c << endl;
                        // cout << "merge : " << y * (W + 1) + x << ", " <<  r * (W + 1) + c << endl;
                    }
                    
                }
            }   
        }else{
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            // for(ll y = 1; y < H + 1; y ++){
            //     for(ll x = 1; x < W + 1; x ++){
            //         if(field[y][x]){
            //             cout << ".";
            //         }else{
            //             cout << "#";
            //         }
            //     }
            //     cout << endl;
            // }
            // cout << "check : " << ra << ", " << ca  << ", " << rb << ", " << cb << endl;
            // cout << "check : " << ra * (W + 1) + ca << ", " <<  rb * (W + 1) + cb << endl;
            if(uf.same(ra * (W + 1) + ca, rb * (W + 1) + cb) && field[ra][ca]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }


}