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
    ll N, K;
    cin >> N >> K;
    vvl vecA(N + 1);
    vl vecL(N + 1);
    for(ll x = 1; x <= N; x ++){
        cin >> vecL[x];
        vecA[x] = vl(vecL[x] + 1);
        for(ll y = 1; y <= vecL[x]; y ++){
            cin >> vecA[x][y];
        }
    }
    ll total = 0;
    for(ll i = 1; i <= N; i ++){
        ll c;
        cin >> c;   
        if(total + (c * vecL[i]) < K){
            total += c * vecL[i];
        }else{
            // cout << total << endl;
            ll idx = (K - total) % vecL[i];
            // cout << idx << endl;
            if(idx == 0){
                
                idx = vecL[i];
            }
            cout << vecA[i][idx] << endl;;
            break;
        }
        

    }
}