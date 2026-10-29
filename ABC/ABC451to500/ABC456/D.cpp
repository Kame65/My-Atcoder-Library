#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <assert.h>
#include <set>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

ll mod = 998244353;
string S;
vvl dpABC;
ll getDpA(ll);
ll getDpB(ll);
ll getDpC(ll);
vc charABC = {'a', 'b', 'c'};

ll getDp(ll abc, ll n){
    
    if(dpABC[abc][n] >= 0){
        
        return dpABC[abc][n];
    }
    

    ll result = 0;
    if(S[n - 1] == charABC[abc]){
        result ++;
        for(ll i = 0; i < 3; i ++){
            result += getDp(i, n - 1);
            result %= mod;
        }
    }else{
        result = getDp(abc, n - 1);
        result %= mod;
    }

    dpABC[abc][n] = result;
    // cout << abc << ", " << n << ", " << dpABC[abc][n] << endl;
    return result;
}

int main(){
    cin >> S;   
    ll N = S.size(); 
    dpABC = vvl(3, vl(N + 1, -1));
    dpABC[0][0] = 0;
    dpABC[1][0] = 0;
    dpABC[2][0] = 0;
    char before = '0';
    ll ans = 0;
    for(ll i = 0; i < 3; i ++){
        ans += getDp(i, N);
        ans %= mod;
        before = S[i - 1];
    }
    cout << ans << endl;

    // cout << getDp(2, 3) << endl;


}
