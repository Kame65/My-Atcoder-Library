#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <assert.h>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

int main(){
    ll N, M;
    cin >> N >> M;
    vl vert(N + 1, 0);
    for(ll i = 0; i < M; i ++){
        ll a, b;
        cin >> a >> b;
        if(a > b){
            vert[a] += 1;
        }else{
            vert[b] += 1;
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i ++){
        if(vert[i] == 1){
            ans ++;
        }
    }
    cout << ans << endl;
}