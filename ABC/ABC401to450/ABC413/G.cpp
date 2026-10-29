#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll H, W, K;
vvl vecK;
unordered_map<ll, bool> judgeMap, already;
ll minH, maxH, minW, maxW;


void bfs(ll r, ll c){
    if(already[r * (W + 1) + c]){
        return;
    }
    if(!judgeMap[r * (W + 1) + c]){
        return;
    }

    already[r * (W + 1) + c] = true;
    if(minH > r){
        minH = r;
    }
    if(maxH < r){
        maxH = r;
    }
    if(minW > c){
        minW = c;
    }
    if(maxW < c){
        maxW = c;
    }
    // cout << r << ", " << c << endl;
    // cout << minH << ", " << maxH << ", " << minW << ", " << maxW << endl;
    for(ll y = -1; y <= 1; y ++){
        for(ll x = -1; x <= 1; x ++){
            // cout << "loc: " << r + y << ", " << c + x << endl;
            if(1 <= r + y && r + y <= H && 1 <= c + x && c + x <= W){
                bfs(r + y, c + x);
            }
            
        }
    }

}

int main(){
    cin >> H >> W >> K;
    vl vecR(K), vecC(K);
    for(ll i = 0; i < K; i ++){
        ll r, c;
        cin >> r >> c;
        vecR[i] = r;
        vecC[i] = c;
        judgeMap[r * (W + 1) + c] = true;
    }

    for(ll i = 0; i < K; i ++){
        minW = W;
        maxW = 1;
        minH = H;
        maxH = 1;
        bfs(vecR[i], vecC[i]);
        if((minW == 1 && maxW == W) || (minH == 1 && maxH == H) || (minW == 1 && minH == 1) || maxW == W && maxH == H){
            cout << "No" << endl;
            return 0;
        }
        // cout << "Clear" << endl;
    }
    cout << "Yes" << endl;



}
