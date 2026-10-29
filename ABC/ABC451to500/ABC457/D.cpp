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


ll N, K;
vl vecA;
bool judge(ll n){// nでできるか
    // cout << "judge" << n << endl;
    ll cnt = 0;
    for(ll i = 1; i <= N; i ++){
        
        if(vecA[i] < n){
            if((n - vecA[i]) % i != 0){
                cnt ++;
            }
            cnt += (n - vecA[i]) / i;
        }
        if(cnt > K){
            return 0;
        }
        // cout << cnt << endl;
    }
    return 1;

}


int main(){

    cin >> N >> K;
    vecA = vl(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    ll r = 3e18;
    ll l = 0;
    while(r - l > 1){
        ll mid = l / 2 + r / 2;
        if(l % 2 == 1 && r % 2 == 1){
            mid += 1;
        }

        // cout << "l = " << l << ", r = " << r << endl;
        // cout << mid << endl;
        if(judge(mid)){
            // cout << "True" << endl;
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << l << endl;

    
    

}