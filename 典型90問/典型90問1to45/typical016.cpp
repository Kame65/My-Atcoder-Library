#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long int;
using namespace std;

int main(){
    ll N, A, B, C;
    vector<ll>vecABC(3);
    cin >> N;
    for(ll i = 0; i < 3; i ++){
        cin >> vecABC[i];
    }
    sort(vecABC.begin(), vecABC.end());
    // cout << vecABC[0] << vecABC[1] << vecABC[2] << endl;
    ll result = 1e4;

    for(ll z =  N / vecABC[2]; z >= 0; z --){
        ll remXY = N - (vecABC[2] * z);
        for(ll y = remXY / vecABC[1]; y >= 0; y --){
            ll remX = remXY - (y * vecABC[1]);
            if(remX % vecABC[0] == 0){
                ll x = remX / vecABC[0];
                if(x + y + z < result){
                    result = x + y + z;
                }
            }
            // cout << result << endl;
        }
    }
    cout << result << endl;


}