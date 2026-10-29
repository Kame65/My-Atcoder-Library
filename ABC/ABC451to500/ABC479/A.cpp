#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N;
    cin >> N;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll ans = 0;
    for(ll i = 0; i < N; i ++){
        if(i % 2 == 0){
            ans += vecA[i];
        }
    }
    cout << ans << endl;

}