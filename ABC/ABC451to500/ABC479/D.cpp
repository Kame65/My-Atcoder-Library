#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vl vecL(N + 1, 0);
    vl vecR(N + 1, 0);
    for(ll i = 2; i <= N; i ++){
        cin >> vecL[i];
    }
    for(ll i = 1; i < N; i ++){
        cin >> vecR[i];
    }
    //左側idx以下でRの最小のもの
    vl minL(N + 1);
    minL[1] = vecR[1];
    for(ll i = 2; i <= N; i ++){
        minL[i] = min(minL[i - 1], vecR[i]);
    }
    vl minR(N + 1);
    minR[N] = vecL[N];
    for(ll i = N - 1; i > 0; i --){
        minR[i] = min(minR[i + 1], vecL[i]);
    }

    for(ll i = 0; i < Q; i ++){
        ll s, t;
        cin >> s >> t;
        ll ans;
        if(s < t){
            ans = min(vecR[s], vecL[s] + minL[s]);
        }
        else{
            ans = min(vecL[s], vecR[s] + minR[s]);
        }
        cout << ans << endl;
    }

    

}