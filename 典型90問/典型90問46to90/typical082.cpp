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
    if(n <= 0){
        return 0;
    }
    ll result = 0;
    ll beforeNum = 0, num = 10;
    ll digit = 1;
    // ll alreadyNum = 0;
    // bool run = true;
    while(beforeNum <= n){//1~9, 10~99, 100~999
        if(n < num){
            num = n + 1;
            // run = false;
        }
        // cout << "beforeNum: " << beforeNum  << ", num: " << num <<endl;//10~10
        ll numA = beforeNum + num - 1;
        ll numB = num - beforeNum;
        if(numA % 2 == 0){
            numA /= 2;
        }else{
            numB /= 2;
        }
        ll tmp = (digit % mod) * (numA % mod) % mod;
        tmp = tmp * (numB % mod) % mod;
        result = (result + tmp) % mod;
        beforeNum = num;
        if(num > 1e17){
            num = n + 1;
        }else{
            num *= 10;
        }
        
        
        digit += 1;
    }
    return result;
}
int main(){
    ll L, R;
    cin >> L >> R;
    cout << (mod + getNum(R) - getNum(L - 1)) % mod << endl;;
    
}
