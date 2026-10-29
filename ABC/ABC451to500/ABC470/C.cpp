#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>

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
    vl vecA(N + 1, 0);
    set<ll> larger;
    ll ans = 0;
    
    ll divCnt = 0;
    for(ll i = 0; i < Q; i ++){
        ll type;
        // cout << "type = " << endl;
        cin >> type;
        
        if(type == 1){
            ll x;
            cin >> x;
            ans ^= vecA[x];
            vecA[x] ++;
            ans ^= vecA[x];
            if(vecA[x] == 1){
                larger.insert(x);
            }
        }else{
            vl delIdx;
            for(ll j: larger){
                ans ^= vecA[j];
                vecA[j] --;
                ans ^= vecA[j];
                if(vecA[j] == 0){
                    delIdx.push_back(j);
                }
            }
            for(ll j: delIdx){
                larger.erase(j);
            }
        }

        cout << ans << endl;
    }
}