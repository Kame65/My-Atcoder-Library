#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;

vector<ll> drinks;

int main(){
    ll N, M;
    cin >> N >> M;
    drinks.resize(M + 1, 1);
    for(ll i = 0; i < N; i ++){
        ll L;
        cin >> L;
        vector<ll> vecX(L, 1);
        for(ll j = 0; j < L; j ++){
            cin >> vecX[j];
        }
        ll idx = 0;
        for(ll j = 0; j < vecX.size(); j ++){
            
            if(drinks[vecX[j]] > 0){
                idx = vecX[j];
                drinks[idx] --;
                break;
            }
        }
        cout << idx << endl;
    }
}