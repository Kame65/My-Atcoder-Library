#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <functional>
#include <string>
#include <set>
#include <math.h>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;
using vb = vector<bool>;

vector<ll> isp;

void sieve(ll largeN) {// largeN以下を探索
    isp = vl(largeN + 1, -1);
    isp[0] = 1;
    isp[1] = 1;
    for (int i=2; pow(i,2) <= largeN; i++) {
        if (isp[i] < 0) for(int j=2; i*j<=largeN; j++) isp[i*j] = i;
    }
}

int main(){
    ll N, K;
    cin >> N >> K;

    sieve(N);
    ll ans = 0;
    for(ll i = 2; i <= N; i ++){
        set<ll> primFactor;
        ll num = i;
        ll cnt = 0;
        while(num > 1){
            ll prim = isp[num];
            if(prim < 0){
                prim = num;
            }
            while(num % prim == 0){
                num /= prim;
            }
            cnt ++;
            if(cnt >= K){
                ans ++;
                break;
            }
            
        }

    }

    // for(ll i = 1; i <= N; i ++){
    //     cout << "i = " << i << " prim factor = " << isp[i] << endl;
    // }

    cout << ans << endl;
}

