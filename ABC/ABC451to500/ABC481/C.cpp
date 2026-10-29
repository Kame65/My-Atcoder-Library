#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll Q; cin >> Q;

    vector<string>vecS(Q);
    for(ll i = 0; i < Q; i ++){
        cin >> vecS[i];
    }
    map<string, bool> judge;
    map<string, ll> id;
    ll idNum = 1;
    for(ll i = 0; i < Q; i ++){
        if(!judge[vecS[i]]){
            judge[vecS[i]] = true;
            id[vecS[i]] = idNum;
            idNum ++;
        }
        cout << id[vecS[i]] << endl;
    }
}