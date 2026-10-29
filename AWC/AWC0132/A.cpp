#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N, P;
    cin >> N >> P;
    vl vecH(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecH[i];
    }
    ll ans = 0;

    for(ll i = 0; i < N; i ++){
        if(P >= vecH[i]){
            P -= vecH[i];
            ans ++;
        }else{
            P += vecH[i];
        }
    }
    cout << ans << endl;

}