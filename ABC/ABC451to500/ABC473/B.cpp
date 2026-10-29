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
    ll N;
    cin >> N;
    vl vecA(101, 0);
    for(ll i = 0; i < N; i ++){
        ll a;
        cin >> a;
        vecA[a] ++;
    }
    ll ans = 0;
    for(ll i = 0; i <= 100; i ++){
        if(vecA[i] % 2 == 1){
            ans += i;
        }
    }
    cout << ans << endl;


    
}
