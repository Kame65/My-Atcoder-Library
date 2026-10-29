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
    ll sumR, sumG, sumB;
    ll finG, finB, res, num;
    T(){
        sumR = 0; sumG = 0; sumB = 0;
        finG = 0; finB = 0;
        res = 0; num = 0;
    }
    T(char c, ll n): T(){
        num = n;
        if(c == 'R') sumR = num;
        if(c == 'G') sumG = num;
        if(c == 'B') sumB = num;
    }

};

T func(T a, T b){

    auto ret = T();
    ret.sumR = (a.sumR + b.sumR) % MOD;
    ret.sumG = (a.sumG + b.sumG) % MOD;
    ret.sumB = (a.sumB + b.sumB) % MOD;
    ret.finB = (a.finB + b.finB + a.sumG * b.sumB) % MOD;
    ret.finG = (a.finG + b.finG + b.sumG * a.sumR) % MOD;// R | G
    ret.res = (a.res + b.res + b.sumB * a.finG + a.sumR * b.finB) % MOD; // RG | B
    return ret;
}

int main(){
    ll N, Q; cin >> N >> Q;
    SegTree<T> seg(N, T(), func);

    vl vecA(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    string S;
    cin >> S;
    for(ll i = 0; i < N; i ++){
        seg.update(i, T(S[i], vecA[i + 1]));
    }
    
    for(ll q = 0; q < Q; q ++){
        int type; cin >> type;
        if(type == 1){
            ll i, x; cin >> i >> x;
            seg.update(i - 1, T(S[i - 1], x));
        }else{
            ll l, r; cin >> l >> r;
            cout << seg.query(l - 1, r).res << endl;
        }

    }


    
}