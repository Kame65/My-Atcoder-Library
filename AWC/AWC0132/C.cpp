#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vl vecP(N), vecD(N);

    for(ll i = 0; i < N; i ++){
        cin >> vecP[i] >> vecD[i];
    }
    vl vecS(Q);
    for(ll i = 0; i < Q; i ++){
        cin >> vecS[i];
    }

    vl res(N + 1, 0);
    res[0] = 2e9;
    ll C = 0;
    // res[i] = P - C -> P >= C  OK
    // res[i] >= KでOK
    for(ll i = 0; i < N; i ++){
        
        res[i + 1] = vecP[i] - C;
        // cout << res[i + 1] << endl;
        C += vecD[i];
    }
    ll min = res[1];
    // cout << "adj: " << endl;
    for(ll i = 1; i <= N; i ++){
        if(min > res[i]){
            min = res[i];
        }
        res[i] = min;
        // cout << min << endl;
    }
    // cout << "ans " << endl;
    for(ll i = 0; i < Q; i ++){
        cout << upper_bound(res.begin(), res.end(), vecS[i], greater<ll>()) - res.begin() - 1 << endl;;
    }

}