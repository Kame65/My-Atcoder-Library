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
    SegTree(ll n_, T inicialElement_, function<T(T, T)> f_){
        this->n = 1;
        while(this->n < n_){
            this->n *= 2;
        } 
        this->inicialElement = inicialElement_;
        this->f = f_;
        data.assign(2 * this->n, this->inicialElement);
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
    T query(int l, int r){
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
        if(r <= il || ir <= l) return inicialElement;
        if(l <= il &&  ir <= r) return data[i];
        ll m = (il + ir) / 2;
        return f(innerQuery(l, r, i << 1 | 0, il, m),
                 innerQuery(l, r, i << 1 | 1, m, ir));
        
    }


    


};



ll funcMax(ll a, ll b){
    return max(a, b);
}



ll W, N;
vl vecL, vecR, vecV;

vector<SegTree<ll>> dp;


int main(){
    ll W, N;
    cin >> W >> N;
    vl vecL(N), vecR(N), vecV(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecL[i] >> vecR[i] >> vecV[i];
    }

    // cout << "what: " << vecV[0] << endl;

    for(ll i = 0; i <= N; i ++){
        // cout<< "i = " << i << " " << vecV[0] << endl;
        SegTree<ll> seg(W + 1, -1, funcMax);
        seg.update(0, 0);
        dp.push_back(seg);
    }
    // cout << vecV[0] << endl;
    
    for(ll n = 1; n <= N; n ++){
        ll idx = n - 1;
        // cout << "n = " << n << " vecV[0] = " << vecV[0] << endl;
        // cout << n << endl;
        for(ll w = 1; w <= W; w ++){
            // cout << "n = " << n << " w = " << w << "v = " << vecV[0] << endl;
            ll val1 = dp[n - 1].query(w, w + 1);
            // cout << "n = " << n << " w = " << w << "v = " << vecV[0] << endl;
            // cout << "val1 = " << val1 << endl;
            ll val2 = -1;
            if(w - vecL[idx] >= 0){
                // cout << "in: " << w - vecL[idx] << endl;

                if(dp[n - 1].query(max((ll)0, w - vecR[idx]), w - vecL[idx] + 1) >= 0){
                    val2 = dp[n - 1].query(max((ll)0, w - vecR[idx]), w - vecL[idx] + 1) + vecV[idx];
                } 
                // cout << "n = " << n << " w = " << w << " idx = " << idx << " " << vecV[idx] << endl;
                // cout << "val2 = " << val2 << endl;
                // cout << "query = " << max((ll)0, w - vecR[idx]) << " " << w - vecL[idx] + 1 << " v = " << vecV[idx] << endl;
            }
            // cout << "n = " << n << " w = " << w << "v = " << vecV[0] << endl;
            dp[n].update(w, max(val1, val2));
            // cout << "n = " << n << " w = " << w << "v = " << vecV[0] << endl;

        }

    }

    cout << dp[N].query(W, W + 1) << endl;


    






    // SegTree<pair<ll, ll>> segTMin(N, make_pair(LLONG_MAX, -1), funcMin);
    // SegTree<ll> a = SegTree(N, -1, funcMax);

    

}

