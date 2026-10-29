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
    ll H, W;
    cin >> H >> W;
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            ll num = 4;
            if(x == 1){
                num --;
            }
            if(x == W){
                num --;
            }
            if(y == 1){
                num --;
            }
            if(y == H){
                num --;
            }
            cout << num << " ";
        }
        cout << endl;
    }
}