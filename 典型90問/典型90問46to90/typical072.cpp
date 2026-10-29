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


ll H, W;
vvc field;
vector<vector<bool>> memoField;
vl dx = {-1, 0, 1, 0};
vl dy = {0, 1, 0, -1};
ll maxVal;

ll getLongest(ll x, ll y, ll sX, ll sY, ll cnt){
    
    if(y == sY && x == sX && cnt >= 3){
        // cout << "cnt = " <<cnt << endl;
        return cnt;
    }
    if(memoField[y][x] || field[y][x] == '#'){
        return -1;
    }
    // cout << x << ", " << y << ", "<< cnt << endl;
    memoField[y][x] = true;
    for(ll i = 0; i < 4; i ++){
        ll len = getLongest(x + dx[i], y + dy[i], sX, sY, cnt + 1);
        if(len > maxVal){
            maxVal = len;
        }
    }
    memoField[y][x] = false;
    return maxVal;
}


int main(){
    cin >> H >> W;
    field = vvc(H + 2, vc(W + 2, '#'));
    maxVal = -1;
    memoField = vector<vector<bool>>(H + 2, vector<bool>(W + 2, false));
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            cin >> field[y][x];
        }
    }


    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            getLongest(x, y, x, y, 0);
        }
    }
    cout << maxVal << endl;
    
    




}