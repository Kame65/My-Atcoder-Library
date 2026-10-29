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
    SegTree(vector<T> vecT, T initialElement_, function<T(T, T)> f_){
        this->n = 1;
        while(this->n < vecT.size()){
            this->n *= 2;
        } 
        this->initialElement = initialElement_;
        this->f = f_;
        data.assign(2 * this->n, this->initialElement);
        for(ll i = 0; i < vecT.size(); i ++){
            update(i, vecT[i]);
        }
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

ll MOD = 998244353;

struct T{
    ll lLen, rLen, len, size;
    ll lnum, rnum;

    T(){
        lLen = 0; rLen = 0;
        lnum = -1; lnum = -1;
        len = 0; size = 0;
    }
    T(ll n): T(){
        lLen = 1; rLen = 1;
        lnum = n; rnum = n;
        len = 1;
        size = 1;
    }

};

T func(T a, T b){
    if(a.size == 0) return b;
    if(b.size == 0) return a;
    auto ret = T();
    ret.lnum = a.lnum;
    ret.rnum = b.rnum;
    ret.size = a.size + b.size;
    if(a.rnum == b.lnum){
        ll val = a.rLen + b.lLen;
        if(a.len <= val && b.len <= val){
            ret.len = val;
        }else{
            ret.len = max(a.len, b.len);
        }

        if(a.lLen == a.size) ret.lLen = val;
        else ret.lLen = a.lLen;

        if(b.rLen == b.size) ret.rLen = val;
        else ret.rLen = b.rLen;

    }else{
        ret.len = max(a.len, b.len);
        ret.lLen = a.lLen;
        ret.rLen = b.rLen;
    }

    
    return ret;
}

int main(){
    ll N, Q; cin >> N >> Q;
    SegTree<T> seg(N, T(), func);

    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }

    for(ll i = 0; i < N; i ++){
        seg.update(i, T(vecA[i]));
    }
    // cerr << "debag" << endl;
    // auto vec = seg.getVector();
    // for(auto e: vec){
    //     cerr << e.rnum << endl;
    // }
    
    for(ll q = 0; q < Q; q ++){
        int type; cin >> type;
        if(type == 1){
            ll i, x; cin >> i >> x;
            seg.update(i - 1, T(x));
        }else{
            ll l, r; cin >> l >> r;
            cout << seg.query(l - 1, r).len << endl;
        }

        // cerr << "Query: " << q + 1 << endl;
        // cerr << "debag" << endl;
        // auto vec = seg.getVector();
        // for(auto e: vec){
        //     cerr << e.rnum << endl;
        // }

    }



    
}