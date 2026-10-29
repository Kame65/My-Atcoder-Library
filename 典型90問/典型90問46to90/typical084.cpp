#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <assert.h>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll oCnt = 0;
    ll xCnt = 0;
    ll ans = N * (N - 1) / 2;
    // cout << ans << endl;
    for(ll i = 0; i < S.size(); i ++){
        if(S[i] == 'o'){
            oCnt ++;
            ans -= xCnt * (xCnt - 1) / 2;
            xCnt = 0;
        }
        if(S[i] == 'x'){
            xCnt ++;
            ans -= oCnt * (oCnt - 1) / 2;
            oCnt = 0;
        }
    }
    ans -= oCnt * (oCnt - 1) / 2;
    ans -= xCnt * (xCnt - 1) / 2;
    cout << ans << endl;
}