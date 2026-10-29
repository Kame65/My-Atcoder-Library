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

vector<vector<char>> ans;

void fill(ll r, ll c, char charX){
    for(ll y = r; y > 0; y --){
        for(ll x = c; x > 0; x --){
            if(ans[y][x] == '.'){
                ans[y][x] = charX;
            }else{
                if(x == c){
                    return;
                }
                continue;
            }
        }
    }
}


int main(){
    ll H, W, Q;
    cin >> H >> W >> Q;
    vl vecR(Q), vecC(Q);
    vector<char> vecX(Q);
    for(ll i = Q - 1; i >= 0; i --){
        // cout << i << endl;
        cin >> vecR[i] >> vecC[i] >> vecX[i];
        // cout << "w";
    }
    // cout << "OK" << endl;;

    ans = vector<vector<char>>(H + 1, vector<char>(W + 1, '.'));
    for(ll i = 0; i < Q; i ++){
        fill(vecR[i], vecC[i], vecX[i]);
    }
    // cout << "OK" << endl;
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            if(ans[y][x] == '.'){
                cout << 'A';
            }else{
                cout << ans[y][x];
            }
        }
        cout << endl;
    }
}