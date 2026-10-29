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

ll K;
vl facs;
ll ans = 0;
unordered_map<ll, bool> res;


int main(){
    cin >> K;
    // unordered_map<ll, ll> fac;
    ll cnt = 0;
    for(ll a = 1; (a - 1) * (a - 1) * (a - 1) < K; a ++){
        
        if(K % a == 0){
            for(ll b = a; a * b * b <= K; b ++){
                if((K / a) % b == 0){
                    cnt ++;
                }
            }
        }
    }
    cout << cnt << endl;
}