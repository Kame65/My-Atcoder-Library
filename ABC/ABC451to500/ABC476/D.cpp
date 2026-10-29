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

    void update(int i, T x){
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



pair<ll, ll> func(pair<ll, ll>a, pair<ll, ll> b){
    return min(a, b);
}

pair<ll, ll> funcMin(pair<ll, ll>a, pair<ll, ll> b){
    return min(a, b);
}

pair<ll, ll> funcMax(pair<ll, ll>a, pair<ll, ll>b){
    return max(a, b);
}

vector<SegTree> dp;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll X, Y;
    cin >> X >> Y;
    vl vecA(N), vecB(M);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < M; i ++){
        cin >> vecB[i];
    }

    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());
    vl cumA(N + 1);
    cumA[0] = 0;
    for(ll i = 0; i < N; i ++){
        cumA[i + 1] = cumA[i] + vecA[i];
    }
    vl cumB(M + 1);
    cumB[0] = 0;
    for(ll i = 0; i < M; i ++){
        cumB[i + 1] = cumB[i] + vecB[i];
    }
    
    ll idxB = 0;
    ll total = X + K * Y;
    ll upper = (upper_bound(cumA.begin(), cumA.end(), total) - cumA.begin()) - 1;
    ll ans = min(upper, N);
    // cout << "f = " << ans << endl;
    while(true){
        if(vecB[idxB] <= K * Y){
            Y -= vecB[idxB] / K;
            if(vecB[idxB] % K != 0){
                Y -= 1;
            }
            total -= vecB[idxB];
            // cout << "buy: " << vecB[idxB] << " total: " << total << endl;
            ll upper = (upper_bound(cumA.begin(), cumA.end(), total) - cumA.begin()) - 1;
            ll num = idxB + 1 + (min(upper, N));
            // cout << "minB = " <<  min(upper, N) << " idxB = " << idxB << " num = " << num << endl;

            if(ans < num){
                ans = num;
            }
            idxB ++;
            if(idxB >= M){
                break;
            }
        }else{
            break;
        }
    }
    cout << ans << endl;

    // for(ll i = 0; i < M ; i ++){
    //     cout << vecB[i] << " ";
    // }
    // cout << endl;
    // for(ll i = 0; i < N + 1; i ++){
    //     cout << cumA[i] << " ";
    // }
    // cout << endl;

   
}
