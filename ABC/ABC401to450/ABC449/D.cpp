#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll L, R, D, U, total;

int main(){
    cin >> L >> R >> D >> U;
    total = 0;

    // x > yの時

    for(ll x = L; x <= R; x ++){
        ll absX = abs(x);
        if(absX % 2 == 0){
            ll plus = min(absX - 1, U) - max(-absX + 1, D) + 1;
            total += max(0ll, plus);
        }
        // cout << x << ": " << total << endl;
       
    }
    // cout << total << endl;
    // x <= yの時
    for(ll y = D; y <= U; y ++){
        ll absY = abs(y);
        if(absY % 2 == 0){
            ll plus = min(R, absY) - max(L, -absY) + 1;
            total += max(0ll, plus);
        }
        // cout << y << ": " << total << endl;
    }

    cout << total << endl;
}