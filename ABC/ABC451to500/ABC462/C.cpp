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
    ll N;
    cin >> N;
    // idx, x, y
    vvl info(N, vl(3));
    for(ll i = 0; i < N; i ++){
        info[i][0] = i;
        cin >> info[i][1] >>info[i][2];
    }
    vector<bool> result(N, false);
    sort(info.begin(), info.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});
    ll ans = 0;
    ll minY = info[0][2];
    for(ll i = 0; i < N; i ++){
        // cout << "minY = " << minY << endl;
        if(minY >= info[i][2]){
            result[i] = true;
            minY = info[i][2];
        }
    }
    sort(info.begin(), info.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[2] < beta[2];});
    ll minX = info[0][1];
    for(ll i = 0; i < N; i ++){
        if(minX >= info[i][1]){
            minX = info[i][1];
        }
    }
    for(ll i = 0; i < N; i ++){
        if(result[i]){
            ans ++;
        }
    }
    cout << ans << endl;
}