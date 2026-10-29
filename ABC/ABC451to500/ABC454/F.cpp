#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <string>

using ll = long long int;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


void solve(){
    ll N, M;
    cin >> N >> M;
    vl vecA(N + 2);
    vecA[0] = 0;
    vecA[N + 1] = 0;
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    vl vecDif;
    for(ll i = 0; i < N + 1; i ++){
        vecDif.push_back((vecA[i + 1] - vecA[i] + M) % M);
    }
    // cout << "VecDif: ";
    // for(ll i = 0; i < vecDif.size(); i ++){
    //     cout << vecDif[i] << " ";
    // }
    // cout << endl;
    ll l = 0, r = vecDif.size() - 1;
    vl vecB;
    while(r >= l){
        if(r != l){
            vecB.push_back((vecDif[l] + vecDif[r]) % M);
        }else{
            vecB.push_back(vecDif[l]);
        }
        l ++;
        r --;
    }
    sort(vecB.begin(), vecB.end());
    // cout << "VecB: ";
    // for(ll i = 0; i < vecB.size(); i ++){
    //     cout << vecB[i] << " ";
    // }
    // cout << endl;
    
    l = 0; r = vecB.size() - 1;
    ll ans = 0;
    //累積和を取る
    vl vecStarts;
    vl vecEnds;
    ll totalL = 0, totalR = 0;
    while(r - l >= 0){
        if(totalL >= totalR){
            totalR += (M - vecB[r]);
            r --;
        }else{
            totalL += vecB[l];
            l ++;
        }
        // cout << "totalR: " << totalR << ", totalL: " << totalL << endl;
    }
    cout << totalL << endl;

    // cout << ans << endl;
}
int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solve();
    }

}