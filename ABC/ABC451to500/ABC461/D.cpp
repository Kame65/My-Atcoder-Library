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

ll H, W, K;
vvl field;

int main(){
    cin >> H >> W >> K;
    field = vvl(H + 2, vl(W + 2, 0));
    for(ll y = 1; y <= H; y ++){
        string str;
        cin >> str;
        for(ll x = 1; x <= W; x ++){
            field[y][x] = str[x - 1] - '0'; 
        }
    }
    vvl sumLines();
    for(ll y0 = 1; y0 <= H; y0 ++){
        vl sumLine(W + 1, 0);
        for(ll y1 = y0; y1 <= H; y1 ++){
            for(ll )
        }
    }
    for(ll y0 = 1; y0 <= H; y0 ++){
        for(ll y1 = y0; y1 <= H; y1 ++){
            
            for(ll x0 = 1; x0 <= W; x0 ++){
                ll val = sumF[y1][x1] - sumF[y1][x0]
            }
        }
    }

}