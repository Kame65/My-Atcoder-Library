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

ll mod = 1e9 + 7;

ll getNum(ll n){
    ll result = 0;
    ll beforeNum = 0, num = 10;
    ll digit = 1;
    ll alreadyNum = 0;
    bool run = true;
    while(run){//1~9, 10~99, 100~999
        if(n < num){
            num = n + 1;
            run = false;
        }
        // cout << "beforeNum: " << beforeNum  << ", num: " << num <<endl;//10~10
        result += digit * ((((beforeNum + num - 1) % mod) * ((num - beforeNum) % mod) / 2) % mod);
        result %= mod;
        beforeNum = num;
        num *= 10;
        
        digit += 1;
    }
    return result;
}
int main(){
    ll L, R;
    cin >> L >> R;
    cout << (mod + getNum(R) - getNum(L - 1)) % mod << endl;;
    
}
