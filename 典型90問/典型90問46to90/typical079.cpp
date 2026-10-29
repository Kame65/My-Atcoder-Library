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
    ll H, W;
    cin >> H >> W;
    vvl field1(H , vl(W));
    vvl field2(H , vl(W));
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            cin >> field1[y][x];
        }
    }
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            cin >> field2[y][x];
        }
    }
    // cout << "=======" << endl;
    ll ans = 0;
    for(ll y = 0; y < H - 1; y ++){
        for(ll x = 0; x < W - 1; x ++){
            ll dif = field2[y][x] - field1[y][x];
            ans += abs(dif);
            field1[y][x] += dif;
            field1[y][x + 1] += dif;
            field1[y + 1][x] += dif;
            field1[y + 1][x + 1] += dif;
            // for(ll y = 0; y < H; y ++){
            //     for(ll x = 0; x < W; x ++){
            //         cout << field1[y][x] << " ";
            //     }
            //     cout << endl;
            // }
        }
    }
    bool same = true;
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            if(field1[y][x] != field2[y][x]){
                same = false;
            }
        }
    }
    if(same){
        cout << "Yes" << endl;
        cout << ans << endl;
    }else{
        cout << "No" << endl;
    }

}