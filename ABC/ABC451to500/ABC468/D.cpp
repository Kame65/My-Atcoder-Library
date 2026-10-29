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
    string S;
    cin >> S;

    ll ans = 0;
    for(ll i = 0; i < S.size(); i ++){
        ll j = 0;
        ll noCnt = 0;
        while(true){
            if(i - j < 0 ||i + j >= S.size()){
                break;
            }
            if(S[i - j] != S[i + j]){
                noCnt ++;
                if(noCnt > 1){
                    break;
                }
            }
            ans ++;
            j ++;
        }
        // cout << i << " " << ans << endl;
    }
    for(ll i = 1; i < S.size(); i ++){
        ll j = 0;
        ll noCnt = 0;
        while(true){
            if(i - j - 1 < 0 ||i + j >= S.size()){
                break;
            }
            if(S[i - j - 1] != S[i + j]){
                noCnt ++;
                if(noCnt > 1){
                    break;
                }
            }
            ans ++;
            j ++;
        }
    }
    cout << ans << endl;
}