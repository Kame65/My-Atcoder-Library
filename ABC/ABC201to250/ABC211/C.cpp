#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>


using namespace std;
using ll = long long int;
vector<ll> dp;

ll mod = pow(10, 9) + 7;


int main(){
    string str;
    cin >> str;
    dp.resize(8);

    for(ll i = 0; i < str.size(); i ++){
        switch (str.at(i)){
            case 'c':
                dp[0] += 1;
                dp[0] %= mod;
                break;
            case 'h':
                dp[1] += dp[0];
                dp[1] %= mod;
                break;
            case 'o':
                dp[2] += dp[1];
                dp[2] %= mod;
                break;
            case 'k':
                dp[3] += dp[2];
                dp[3] %= mod;
                break;
            case 'u':
                dp[4] += dp[3];
                dp[4] %= mod;
                break;
            case 'd':
                dp[5] += dp[4];
                dp[5] %= mod;
                break;
            case 'a':
                dp[6] += dp[5];
                dp[6] %= mod;
                break;
            case 'i':
                dp[7] += dp[6];
                dp[7] %= mod;
                break;
            default:
                break;
        }   
        
    }
    cout << dp[7] << endl;
}