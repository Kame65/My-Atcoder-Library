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
    T initialElement;
    function<T(T, T)> f;
    // 初期化
    //2 * nの大きさのdataをinicialElementで埋める(INT_MAXなど)
    // fは比較関数
    SegTree(ll n_, T initialElement_, function<T(T, T)> f_){
        this->n = 1;
        while(this->n < n_){
            this->n *= 2;
        } 
        this->initialElement = initialElement_;
        this->f = f_;
        data.assign(2 * this->n, this->initialElement);
    }

    void update(ll i, T x){
        i += n;
        data[i] = x;
        while(i > 1){
            i >>= 1;// i /= 2と同じ
            // i << 1 | 0は2i, i << 1 | 1は2i + 1
            data[i] = f(data[i << 1 | 0], data[i << 1 | 1]);

        }
    }
    // T innerQuery(int l, int r, int i, int il, int ir);
    T query(ll l, ll r){
        return innerQuery(l, r, 1, 0, n);
    }

    vector<T> getVector(){
        vector<T> res;
        for(ll i = 0; i < n; i ++){
            res.push_back(data[n + i]);
        }
        return res;
    }

    private:
    T innerQuery(int l, int r, int i, int il, int ir){
        if(r <= il || ir <= l) return initialElement;
        if(l <= il &&  ir <= r) return data[i];
        ll m = (il + ir) / 2;
        return f(innerQuery(l, r, i << 1 | 0, il, m),
                 innerQuery(l, r, i << 1 | 1, m, ir));
        
    }
};

pair<ll, ll> func(pair<ll, ll>a, pair<ll, ll> b){
    return min(a, b);
}

pair<ll, ll> funcMin(pair<ll, ll>a, pair<ll, ll> b){
    return min(a, b);
}

pair<ll, ll> funcMax(pair<ll, ll>a, pair<ll, ll>b){
    return max(a, b);
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    SegTree<ll> segTMin(N + 1, LLONG_MAX, [](ll a, ll b){return min(a, b);});

    for(ll i = 1; i <= N; i ++){
        ll a;
        cin >> a;
        segTMin.update(i, a);
    }
    for(ll i = 0; i < Q; i ++){
        ll t; cin >> t;
        if(t == 1){
            ll i, x; cin >> i >> x;
            segTMin.update(i, x);
        }else{
            ll l, r; cin >> l >> r;
            cout << segTMin.query(l, r + 1) << endl;
        }
    }


}