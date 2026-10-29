#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long int;


ll x, N, Q;
vector<ll> listW, listP;
vector<bool> wearring;

 
int main(){
    cin >> x >> N;
    for(ll i = 0; i < N; i ++){
        ll w;
        cin >> w;
        listW.push_back(w);
    }
    cin >> Q;
    wearring.resize(N, false);
    for(int i = 0; i < Q; i ++){
        ll p;
        cin >> p;
        listP.push_back(p);
    }
    for(int i = 0; i < Q; i ++){
        ll p = listP[i];
        if(!wearring[p - 1]){
            wearring[p - 1] = true;
            x += listW[p - 1];
        }else{
            wearring[p - 1] = false;
            x -= listW[p - 1];
        }
        cout << x << endl;
    }


}
