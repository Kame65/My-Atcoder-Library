#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


ll K, L, N;
vector<ll> vecA, parts;



bool judge(ll n){
    ll len = 0;
    ll cutCnt = 0;
    for(ll i = 0; i <= N; i ++){
        len += parts[i];
        if(len >= n){
            // cout << "cutLen: " << len << " cnt = " << cutCnt << endl;
            len = 0;
            cutCnt += 1;
        }
    }
    if(cutCnt > K){
        return true;
    }
    return false;

}

int main(){
    cin >> N >> L >> K;
    vecA.resize(N);
    parts.resize(N + 1);
    
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    parts[0] = vecA[0];
    for(ll i = 1; i < N; i ++){
        // cout << "i = " << i << endl;
        parts[i] = vecA[i] - vecA[i - 1];
        // cout << parts[i] << endl;
    }
    parts[N] = L - vecA[N - 1];

    ll l = 0;
    ll r = L + 1;


    while(r - l > 1){
        ll mid = (r + l) / 2;
        if(judge(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    // cout << "parts: " << endl;
    // for(ll i = 0; i <= N; i ++){
    //     cout << parts[i] << " ";
    // }
    // cout << endl;
    cout << l << endl;
    // cout << judge(20) << endl;

}