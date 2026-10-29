#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long int;

ll N, D;
vector<ll> vecA, results;
set<ll> setB;

int main(){
    cin >> N >> D;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll l, r;
    l = 0;
    r = 1;
    setB.insert(vecA[0]);
    results.resize(N, 0);
    while(l < N){
        ll val = vecA[r];
        // cout << l << ", " << r << ", " << endl;
        auto iterR = setB.lower_bound(val);
        bool can = true;
        if(iterR != setB.end()){
            ll rV = *iterR;
            // cout << "rV - val: " << abs(rV - val) << endl;
            if(abs(rV - val) < D){
                can = false;
            }
            // cout << "rV = " << rV << ", val = " << val << endl;
        }
        if(iterR != setB.begin()){
            auto iterL = -- iterR;
            ll lV = *iterR;
            // cout << "vL - val: " << abs(lV - val) << endl;
            if(abs(lV - val) < D){
                can = false;
            }

        }
        if(can){
            if(r < N - 1){
                setB.insert(vecA[r]);
                r ++;
            }else{
                setB.erase(vecA[l]);
                results[l] = r + 1;
                l ++;
            }
            

        }else{
            setB.erase(vecA[l]);
            results[l] = r;
            l ++;
        }

    }
    ll ans = 0;
    for(ll i = 0; i < N; i ++){
        ans += results[i] - i ;
    }
    // for(ll i = 0; i < N; i ++){
    //     cout << results[i] << endl;
    // }
    cout << ans << endl;

}