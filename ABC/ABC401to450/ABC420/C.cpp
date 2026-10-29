#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

ll N, Q;
vector<ll> vecA, vecB, vecC, vecX, vecV;


int main(){
    cin >> N >> Q;
    vecA.resize(N + 1);
    vecB.resize(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 1; i <= N; i ++){
        cin >> vecB[i];
    }

    ll total = 0;
    for(ll i = 1; i <= N; i ++){
        total += min(vecA[i], vecB[i]);
    }

    vecC.resize(Q);
    vecX.resize(Q);
    vecV.resize(Q);
    for(ll i = 0; i < Q; i ++){
        char c;
        ll x, v;
        cin >> c >> x >> v;
        ll beforeMinX = min(vecA[x], vecB[x]);
        if(c == 'A'){
            vecA[x] = v;
        }else{
            vecB[x] = v;
        }
        ll afterMinX = min(vecA[x], vecB[x]);
        total += afterMinX - beforeMinX;
        cout << total << endl;
    }
    

}
