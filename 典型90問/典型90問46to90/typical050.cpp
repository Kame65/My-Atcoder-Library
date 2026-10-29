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




ll mod = 1e9 + 7;
ll N, L;
vl dp;

ll getDp(ll n){// n段目に登る
    if(n < 0){
        return 0;
    }
    if(dp[n] >= 0){
        return dp[n];
    }
    ll total = 0;
    total += getDp(n - 1);
    total += getDp(n - L);
    total %= mod;
    dp[n] = total;
    return dp[n];
}
int main(){
    cin >> N >> L;
    dp = vl(N + 1, -1);
    dp[0] = 1;
    cout << getDp(N) << endl;



}