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


void solveCase(){
    ll X, Y, K;
    cin >> X >> Y >> K;
    ll ans = 0;
    ll x = X;
    ll y = Y;
    while(x != y){
        if(x > y){
            x = x / K;
        }else{
            y = y / K;
        }
        ans ++;
    }
    cout << ans << endl;
}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}