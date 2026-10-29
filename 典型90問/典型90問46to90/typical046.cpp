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
    

    vvl vecABC = {vl(46, 0), vl(46, 0), vl(46, 0)};
    for(ll i = 0; i < 3; i ++){
        for(ll j = 0; j < N; j ++){
            ll num;
            cin >> num;
            vecABC[i][num % 46] += 1;
        }
        
    }
    ll ans = 0;
    for(ll a = 0; a < 46; a ++){
        for(ll b = 0; b < 46; b ++){
            for(ll c = 0; c < 46; c ++){
                if((a + b + c) % 46 == 0){
                    ans += vecABC[0][a] * vecABC[1][b] * vecABC[2][c];
                }
            }
        }
    }
    cout << ans << endl;
}

