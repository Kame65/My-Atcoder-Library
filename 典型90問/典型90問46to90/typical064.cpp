#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>


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

    vl vecA(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    vl vecDif(N + 1, 0);
    ll cost = 0;
    for(ll i = 1; i < N; i ++){
        
        vecDif[i] = vecA[i] - vecA[i + 1];
        // cout << i << ", " << vecDif[i] << ", " << vecA[i] << ", " << vecA[i + 1] << endl;
        cost += abs(vecDif[i]);
    }
    // cout << "vecDif: ";
    // for(ll j = 1; j < N; j ++){
    //     cout << vecDif[j] << " ";
    // }
    //     cout << endl;
    for(ll i = 0; i < Q; i ++){
        ll l, r, v;
        cin >> l >> r >> v;
        

        if(l != 1){
            cost -= abs(vecDif[l - 1]);
            vecDif[l - 1] -= v;
            cost += abs(vecDif[l - 1]);
        }

        if(r != N){
            cost -= abs(vecDif[r]);
            vecDif[r] += v;
            cost += abs(vecDif[r]);
        }
        
        cout << cost << endl;
        // cout << "vecDif: ";
        // for(ll j = 1; j < N; j ++){
        //     cout << vecDif[j] << " ";
        // }
        // cout << endl;

    }
}