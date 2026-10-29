#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N;
    cin >> N;
    vl vecS(N), vecC(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecS[i] >> vecC[i];
    }
    vl sortedS = vecS;
    ll ans = 0;

    sort(sortedS.begin(), sortedS.end());
    for(ll i = 0; i < N; i ++){
        // cout << sortedS[i] << " ";    
    }
    // cout << endl;
    for(ll i = 0; i < N; i ++){
        // cout << vecS[i] << "<= x < " << vecC[i] << endl;
        if(vecC[i] > vecS[i]){
            // cout << "maxIdx = " << lower_bound(sortedS.begin(), sortedS.end(), vecC[i]) - sortedS.begin() << endl;
            // cout << "minIdx = " << lower_bound(sortedS.begin(), sortedS.end(), vecS[i]) - sortedS.begin() << endl;
            ans += lower_bound(sortedS.begin(), sortedS.end(), vecC[i]) - lower_bound(sortedS.begin(), sortedS.end(), vecS[i]) - 1 ;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;

}