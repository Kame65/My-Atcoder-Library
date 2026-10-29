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
    ll N, S, L;
    cin >> N >> S >> L;
    vl vecA(N);
    for(ll i = 1; i < N; i ++){
        cin >> vecA[i];
    }

    vl vecLeft(N, 1e18 + 100000);
    vl vecRight(N, 1e18 + 100000);
    ll cntR = 1;
    ll before = 0;
    vecRight[0] = 0;

    for(ll i = S; i < N; i ++){
        vecRight[cntR] = before + vecA[i];
        before = vecRight[cntR];
        cntR ++;
    }
    ll cntL = 1;
    before = 0;
    vecLeft[0] = 0;
    
    for(ll i = S - 1; i > 0 ; i --){
        vecLeft[cntL] = before + vecA[i];
        before = vecLeft[cntL];
        cntL ++;
    }
    ll ans = 1;
    
    for(ll i = 0; i < N; i ++){
        ll limit = L;
        ll res = 1;
        if(vecRight[i] <= limit){
            res += i;
            limit -= vecRight[i] * 2;
            if(limit > 0){
                res += upper_bound(vecLeft.begin(), vecLeft.end(), limit) - vecLeft.begin() - 1;
                // cout << "lower" << lower_bound(vecLeft.begin(), vecLeft.end(), limit) - vecLeft.begin() << endl;
            }
            if(ans < res){
                ans = res;
            }
            // cout << "right: " << i << " " << res << endl;

        }else{
            break;
        }
    }

    for(ll i = 0; i < N; i ++){
        ll limit = L;
        ll res = 1;
        if(vecLeft[i] <= limit){
            res += i;
            limit -= vecLeft[i] * 2;
            if(limit > 0){
                res += upper_bound(vecRight.begin(), vecRight.end(), limit) - vecRight.begin() - 1;
            }
            if(ans < res){
                ans = res;
            }
            // cout << "left: " << i << " " << res << endl;

        }else{
            break;
        }
    }

    cout << ans << endl;

    // for(ll i = 0; i < N; i ++){
    //     cout << vecLeft[i] << " ";
    // }
    // cout << endl;

    // for(ll i = 0; i < N; i ++){
    //     cout << vecRight[i] << " ";
    // }
    // cout << endl;

}
