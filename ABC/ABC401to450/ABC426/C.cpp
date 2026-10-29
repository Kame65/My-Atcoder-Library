#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

ll N, Q;
vector<ll> vecX, vecY, totalNi;

int main(){
    cin >> N >> Q;
    vecX.resize(Q);
    vecY.resize(Q);

    for(ll i = 0; i < Q; i ++){
        cin >> vecX[i] >> vecY[i];
    }

    totalNi.resize(N + 1, 1);

    
    ll min = 1;

    for(ll i = 0; i < Q; i ++){
        ll x, y;
        x = vecX[i];
        y = vecY[i]; 
        ll change = 0;
        
        for(ll j = min; j <= x; j ++){
            change += totalNi[j];

        }
        totalNi[y] += change;
        // cout << min << " " << y << " " << totalNi[y] << endl;
        if(min < x + 1){
            min = x + 1;
        }
        
        cout << change << endl;
    }

}