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

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;
using vb = vector<bool>;

vector<bool> isp;
vector<ll> primNum;

void sieve(ll largeN) {// largeN以下を探索
    isp = vb(largeN + 1, true);
    primNum = vl(largeN + 1, 0);
    isp[0] = false;
    isp[1] = false;
    for (int i=2; pow(i,2) <= largeN; i++) {
        if (isp[i]) {
            for(int j = 2; i * j <= largeN; j ++){
                isp[i * j] = false;
                primNum[i * j] += 1;
            }
        }
    }
}

int main(){
    ll N, K;
    cin >> N >> K;

    sieve(N);
    ll ans = 0;
    for(ll i = 2; i <= N; i ++){
        ll res = primNum[i];
        if(isp[i]){
            res ++;
        }
        if(res >= K){
            ans ++;
        }
        
    }


    cout << ans << endl;

    for(ll i = 1; i <= N; i++){
        cout << "i = " << i << " primNum = " << primNum[i] << endl;
    }
}

