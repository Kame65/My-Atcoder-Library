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
    vector<string> vecC(H);
    for(ll y = 0; y < H; y ++){
            
            cin >> vecC[y];
            // cout << vecC[y] << endl;

    }

    ll minX = W, minY = H, maxX = 0, maxY = 0;
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            // cout << y << "," << x << endl;
            // cout << vecC[y][x];
            if(vecC[y][x] == '#'){
                if(minY > y){
                    minY = y;
                }
                if(minX > x){
                    minX = x;
                }
                if(maxX < x){
                    maxX = x;
                }
                if(maxY < y){
                    maxY = y;
                }
            }
        }
    }
    // cout << minY << endl;
    for(ll y = minY; y <= maxY; y ++){
        for(ll x = minX; x <= maxX; x ++){
            cout << vecC[y][x];
        }
        cout << endl;
    }
    
}