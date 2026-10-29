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


ll H, W;
vvc vecS;
bool judge(ll x0, ll y0, ll x1, ll y1){
    for(ll i = y0; i <= y1; i ++){
        for(ll j = x0; j <= x1; j ++){
            // cout << x0 << ", " << y0 << " " << x1 << " " << y1 << endl;
                if(vecS[i][j] != vecS[y0 + y1 - i][x0 + x1 - j]){
                return false;
            }   
        }
    }
    return true;
}
int main(){
    cin >> H >> W;
    vecS = vvc(H + 2, vc(W + 2));
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            cin >> vecS[y][x];
        }
    }
    ll ans = 0;
    for(ll y0 = 1; y0 <= H; y0 ++){
        for(ll x0 = 1; x0 <= W; x0 ++){
            // cout << x0 << endl;
            for(ll y1 = y0; y1 <= H; y1 ++){
                for(ll x1 = x0; x1 <= W; x1 ++){
                        
                    if(judge(x0, y0, x1, y1)){
                        // cout << x0 << " " << y0 << " " << x1 << " " << y1 << ": " << ans << endl ;
                        ans ++;
                    }
                    // cout << x0 << " " << y0 << " " << x1 << " " << y1 << ": " << ans << endl ;
                }
            }
        }
    }
    cout << ans << endl;
}