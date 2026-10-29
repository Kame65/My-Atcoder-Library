#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main(){
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> vecB(H, vector<ll>(W));
    vector<ll> vecSumX(W, 0), vecSumY(H, 0);
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            ll val;
            cin >> val;
            vecB[y][x] = val;
            vecSumX[x] += val;
            vecSumY[y] += val;
        }
    }
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            cout << vecSumX[x] + vecSumY[y] - vecB[y][x] << " ";
        }
        cout << endl;
    }
}