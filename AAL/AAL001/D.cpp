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

struct T{
    ll sum0;
    ll sum1;
    ll sum2;
    ll size;
    ll inv;
    T(ll s0, ll s1, ll s2, ll si, ll in){
        sum0 = s0; sum1 = s1; sum2 = s2;
        size = si; inv = in;
    }
    T(){
        sum0 = 0; sum1 = 0; sum2 = 0;
        size = 0; inv = 0;
    }
};

T func(T a, T b){
    ll s0 = a.sum0 + b.sum0;
    ll s1 = a.sum1 + b.sum1;
    ll s2 = a.sum2 + b.sum2;
    ll in = b.sum0 * (a.sum1 + a.sum2) + b.sum1 * a.sum2 + a.inv + b.inv;
    ll si = a.size + b.size;
    return T(s0, s1, s2, si, in);
}

int main(){
    ll N, Q; cin >> N >> Q;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];    
    }
    SegTree<T> seg(N, T(0, 0, 0, 0, 0), func);



    for(ll i = 0; i < N; i ++){
        if(vecA[i] == 0){
            seg.update(i, T(1, 0, 0, 1, 0));
        }
        if(vecA[i] == 1){
            seg.update(i, T(0, 1, 0, 1, 0));;
        }
        if(vecA[i] == 2){
            seg.update(i, T(0, 0, 1, 1, 0));
        }
    }
    for(ll q = 0; q < Q; q ++){
        int type; cin >> type;
        if(type == 1){
            int i, x; cin >> i >> x;
            i --;
            if(x == 0){
                seg.update(i, T(1, 0, 0, 1, 0));
            }
            if(x == 1){
                seg.update(i, T(0, 1, 0, 1, 0));;
            }
            if(x == 2){
                seg.update(i, T(0, 0, 1, 1, 0));
            }
        }else{
            int l, r; cin >> l >> r;
            cout << seg.query(l - 1, r).inv << endl;
        }

    }
    // cerr << seg.query(0, 1).inv << endl;




    
}