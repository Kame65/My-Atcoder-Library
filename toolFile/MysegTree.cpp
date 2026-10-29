#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <climits>
#include <functional>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

template <typename T>
struct SegTree{
    ll n;
    vector<T> data;
    T inicialElement;
    function<T(T, T)> f;
    // 初期化
    //2 * nの大きさのdataをinicialElementで埋める(INT_MAXなど)
    // fは比較関数
    SegTree(ll n, T inicialElement, function<T(T, T)> f){
        data.assign(2 * this->n, e);
    }

    void update(int i, T x){
        i += n;
        data[i] = x;
        while(i > 0){
            i >>= 1;// i /= 2と同じ
            // i << 1 | 0は2i, i << 1 | 1は2i + 1
            data[i] = f(data[i << 1 | 0], data[i << 1 | 1]);

        }
    }

    T query(int l, int r){
        return innerQuery(l, r, 1, 0, n);
    }


    T innerQuery(int l, int r, int i, int il, int ir){
        if(r <= il || ir <= l) return inicialElement;
        if(l <= il &&  ir <= r) return data[i];
        ll m = (il + ir) / 2;
        return f(innerQuery(l, r, i << 1 | 0, il, m)),
                 innerQuery(l, r, i << 1 | 1, m, ir);
        
    }
    


};

pair<ll, ll> func(pair<ll, ll>a, pair<ll, ll> b){
    return min(a, b);
}

int main(){
    ll N;
    cin >> N;

    SegTree<pair<ll, ll>> segTree(N, make_pair(INT_MAX, -1), func);

}