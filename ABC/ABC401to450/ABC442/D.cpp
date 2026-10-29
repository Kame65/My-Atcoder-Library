#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll N, Q;
    cin >> N >> Q;
    vl vecA(N + 1, 0), totalA(N + 1, 0);

    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
        totalA[i] = vecA[i] + totalA[i - 1];
    }
    for(ll i = 0; i < Q; i ++){
        ll qtype;
        cin >> qtype;

        if(qtype == 1){
            ll x;
            cin >> x;
            ll vecAxBefore = vecA[x];
            totalA[x] = totalA[x] - vecA[x] + vecA[x + 1];
            vecA[x] = vecA[x + 1];
            vecA[x + 1] = vecAxBefore;

        }
        if(qtype == 2){
            ll left, right;
            cin >> left >> right;
            cout << totalA[right] - totalA[left - 1] << endl;
        }
    }
    


    
}