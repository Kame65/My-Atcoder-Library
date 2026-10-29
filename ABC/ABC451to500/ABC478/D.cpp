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
    vl res(N + 2, 0);
    unordered_map<ll, ll>minMap, maxMap;
    unordered_map<ll, bool> used;
    for(ll i = 0; i < Q; i ++){
        ll l, r, x;
        cin >> l >> r >> x;
        if(used[x]){
            if(minMap[x] <= l && r <= maxMap[x]){
                continue;
            }
            if(l < minMap[x]){
                ll right = min(minMap[x] - 1, r);
                res[l] ++;
                res[l] ++;
                res[right + 1] --;
                minMap[x] = l;
            }
            if(maxMap[x] < r){
                // cout << "update" << endl;
                // cout << maxMap[x] << " " << r << endl;
                ll left = max(maxMap[x] + 1, l);
                res[left] ++;
                res[r + 1] --;
                maxMap[x] = r;
            }
        }else{
            res[l] ++ ;
            res[r + 1] -- ;
            minMap[x] = l;
            maxMap[x] = r;
            used[x] = true;
        }
        // cout << "res: ";
        // for(ll i = 1; i <= N; i ++){
        //     cout << res[i] << " ";
        // }
        // cout << endl;


    }
    

    for(ll i = 1; i <= N; i ++){
        res[i] = res[i - 1] + res[i];
    }
    for(ll i = 1; i <= N; i ++){
        cout << res[i] << " ";
    }
    cout << endl;

}
