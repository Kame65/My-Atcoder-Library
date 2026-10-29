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
    vl vecP(N + 1, 0), vecPP(N + 1, 0);
    
    for(ll i = 1; i <= N; i ++){
        cin >> vecP[i];
        vecPP[vecP[i]] = i;
    }
    bool flip = false;
    for(ll i = 0; i < Q; i ++){
        ll type;
        cin >> type;
        if(type == 1){
            ll x, y;
            cin >> x >> y;
            if(!flip){
                swap(vecPP[vecP[x]], vecPP[vecP[y]]);
                swap(vecP[x], vecP[y]);
            }else{
                swap(vecP[vecPP[x]], vecP[vecPP[y]]);
                swap(vecPP[x], vecPP[y]);
            }
        }else{
            flip = !flip;
        }
    }

    for(ll i = 1; i <= N; i ++){
        if(flip){
            cout << vecPP[i] << " ";
        }else{
            cout << vecP[i] << " ";
        }
    }
    cout << endl;
}