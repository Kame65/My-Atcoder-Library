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


int main(){
    ll N, P, Q;
    cin >> N >> P >> Q;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll ans = 0;
    for(ll i1 = 0; i1 < N - 4; i1 ++){
        for(ll i2 = i1 + 1; i2 < N - 3; i2 ++){
            for(ll i3 = i2 + 1; i3 < N - 2; i3 ++){
                for(ll i4 = i3 + 1; i4 < N - 1; i4 ++){
                    for(ll i5 = i4 + 1; i5 < N; i5 ++){
                        ll val12 = (vecA[i1] * vecA[i2]) % P;
                        ll val34 = (vecA[i3] * vecA[i4]) % P;
                        ll val1234 = (val12 * val34) % P;
                        if((val1234 * vecA[i5]) % P == Q){
                            ans ++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}