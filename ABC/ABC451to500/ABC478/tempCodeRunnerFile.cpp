#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vl res(N + 2, 0);
    unordered_map<ll, ll>minMap, maxMap;
    unordered_map<ll, bool> used;
    vector<vector<ll>> vecInfo(Q);
    for(ll i = 0; i < Q; i ++){
        ll l, r, x;
        cin >> l >> r >> x;
        vecInfo[i] = {l, r, x};
    }
    sort(vecInfo.begin(),vecInfo.end(),[](const vector<ll> &alpha,const vector<ll> &beta){if(alpha[2] < beta[2]) return true; if(alpha[2] == beta[2] && alpha[0] < beta[0]) return true;return false;});
    ll maxR = 0;
    ll beforeX = 0;
    for(ll i = 0; i < Q; i ++){
        ll l, r, x;
        cout << i << endl;
        l = vecInfo[i][0];
        r = vecInfo[i][1];
        x = vecInfo[i][2];
        if(beforeX != x){
            maxR = 0;
            res[l] ++;
            res[r + 1]--;
            maxR = r;
        }else{
            if(maxR < r){
                res[max(l, maxR + 1)] ++;
                res[r + 1] --;
                maxR = r;
            }
        }
        beforeX = x;
        // for(ll i = 1; i < N + 1; i ++){
        //     cout << res[i] << " ";
        // }
        // cout << endl;

    }

    

    for(ll i = 1; i <= N; i ++){
        res[i] = res[i - 1] + res[i];
    }
    for(ll i = 1; i <= N; i ++){
        cout << res[i] << " ";
    }
    cout << endl;

}
