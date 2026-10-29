#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long int;


ll N, Q;
vector<vector<ll>> vecA;


ll solveQ(){
    ll K;
    cin >> K;
    vector<bool> there(N + 1, false);
    for(ll i = 0; i < K; i ++){
        ll j;
        cin >> j;
        there[j] = true;
    }
    for(ll i = 0; i < N; i ++){
        if(!there[vecA[i][0]]){
            return vecA[i][1];
        }
    }
    return 0;
    
}

int main(){
    cin >> N >> Q;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        vecA[i].resize(2);
        vecA[i][0] = i + 1;
        cin >> vecA[i][1];
    }
    sort(vecA.begin(),vecA.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});


    // for(ll i = 0; i < N; i ++){
    //     cout << vecA[i][0] << " ";
    // }
    // cout << endl;
    // for(ll i = 0; i < N; i ++){
    //     cout << vecA[i][1] << " ";
    // }
    // cout << endl;
    for(ll i = 0; i < Q; i ++){
        cout << solveQ() << endl;
    }

}