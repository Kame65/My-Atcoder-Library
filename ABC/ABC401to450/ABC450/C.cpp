#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
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

ll H, W;
vector<vector<char>> field;
vl dirX = {-1, 0, 1, 0};
vl dirY = {0, 1, 0, -1};

int main(){
    cin >> H >> W;
    field.resize(H);
    dsu uf(H * W + 1);
    for(ll i = 0; i < H; i ++){
        field[i].resize(W);
        for(ll j = 0; j < W; j ++){
            cin >> field[i][j]; 
            // cout << "input: " << i << ", " << j << endl;
            if(field[i][j] == '#'){
                uf.merge(W * H, W * i + j);
                // cout << uf.groups().size() << endl; 
            }
                          
        }
    }
    // cout << "end" << endl;


    
    for(ll i = 0; i < H ; i ++){
        for(ll j = 0; j < W ; j ++){
            if(field[i][j] == '.'){
                // cout << i << ", " << j << endl;
                
                for(int k = 0; k < 4; k ++){
                    int neiX = j + dirX[k];
                    int neiY = i + dirY[k];
                    // cout << neiX << ",," << neiY << endl;
                    if(0 <= neiX && neiX < W && 0 <= neiY && neiY < H){
                        // cout << "OK: " << neiX << ", " << neiY << endl;
                        if(field[neiY][neiX] == '.'){
                            
                            
                            if(!uf.same(W * i + j, W * neiY + neiX)){
                                // cout << i << ", " << j << " : " << neiX << neiY << endl;
                                uf.merge(W * i + j, W * neiY + neiX);
                            }
                        }
                    }
                    else{
                        if(!uf.same(W * i + j, W * H)){
                            uf.merge(W * i + j, W * H);
                        }
                    }
                }
            }
        }
    }
    cout << uf.groups().size() - 1 << endl;




}