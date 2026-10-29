#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, K, T;
    cin >> N >> K >> T;
    vl vecA(N);
    for(int i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    sort(vecA.begin(), vecA.end());
    ll idx = 0;
    ll t = 0;
    ll ans = 0;
    while(t < T){
        // cerr << "t = " << t << endl;
        // cerr << "ans = " << ans << endl;
        // cerr << "idx = " << idx << endl;
        if(idx >= N){
            ll num = (T - t) / K;
            t += K * num;
            ans += num;
            if(t < T){
                ans ++;
                t += K;
            }
        }else if(vecA[idx] > t){
            ll num = (min(vecA[idx], T) - t) / K;
            t += K * num;
            ans += num;
            if(t < min(vecA[idx], T)){
                t += K;
                ans ++;
            }
        }else{
            t = max(vecA[idx] + K, t);
            idx ++;
        }
    }
    cout << ans << endl;
}