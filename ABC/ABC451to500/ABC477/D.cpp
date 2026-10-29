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

    vector<ll> type(Q);
    vector<ll> vecX;
    vector<char> vecC(1, 'a');
    vector<bool> open(N + 1, true);

    for(ll i = 0; i < Q; i ++){
        cin >> type[i];
        if(type[i] == 1){
            ll x;
            cin >> x;
            vecX.push_back(x);
            open[x] = !open[x];
        }
        else{
            char c;
            cin >> c;
            vecC.push_back(c);
        }
    }
    vector<char> result(N + 1, 'a');
    vector<bool> ok(N + 1, false);
    set<ll>canChange;
    for(ll i = 1; i <= N; i ++){
        if(open[i]){
            canChange.insert(i);
        }
    }



    ll Cidx = vecC.size() - 1;
    ll Xidx = vecX.size() - 1;
    for(ll i = Q - 1; i >= 0; i --){
        if(type[i] == 1){
            ll x = vecX[Xidx];
            Xidx --;
            // cout << "x = " << x << endl;
            if(open[x]){ // open状態だった
                canChange.erase(x);
                
            }else{
                if(!ok[x]){
                    canChange.insert(x);
                }
                
            } 
            open[x] = !open[x];
        }else{
            // if(Cid)
            char c = vecC[Cidx];
            Cidx --;

            for(ll x: canChange){
                result[x] = c;
                ok[x] = true;
            }
            canChange.clear();
        }
    }
    // for(ll i = 1; i <= N; i ++){
    //     cout << open[i] << " ";
    // }
    // cout << endl;
    for(ll i = 1; i <= N; i ++){
        cout << result[i];
    }
    cout << endl;
}
