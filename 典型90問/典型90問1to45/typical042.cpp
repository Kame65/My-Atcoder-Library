#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;




vl dp;
ll K;
ll mod = 1e9 + 7;

ll getDp(ll k){
    if(k < 0){
        return 0;
    }
    if(dp[k] >= 0){
        return dp[k];
    }

    ll total = 0;
    for(ll i = 1; i <= 9; i ++){
        if(k - i < 0){
            break;
        }
        total += getDp(k - i);
        total %= mod;
        // cout << k << " " << k - i << " " << getDp(k - i) << endl;
    }
    
    if(k <= 9){
        total += 1;
    }
    dp[k] = total;
    return total;
}




int main(){

    cin >> K;
    dp = vl(K + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    if(K % 9 != 0){
        cout << 0 << endl;
    }else{
        cout << getDp(K) << endl;
    }
    // cout << getDp(K) << endl;;
    
  
}