#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;


ll N, M, L, S, T;
vl vecU, vecV, vecC;
vvvl vecUtoV;
vvl dp;
vector<vector<vector<ll>>> searched;

void search(ll l){
    for(ll i = 0; i < searched[l].size(); i ++){
        ll u = searched[l][i][0];
        ll cost = searched[l][i][1];
        for(ll j = 0; j < vecUtoV[u].size(); j ++){
            ll v = vecUtoV[u][j][0];
            ll c = vecUtoV[u][j][1];
            if(cost + c <= T){
                vector<ll> s = {v, cost + c};
                searched[l + 1].push_back(s);
            }
        }

    }
}

int main(){
    cin >> N >> M >> L >> S >> T;
    vecU.resize(M);
    vecV.resize(M);
    vecC.resize(M);
    for(ll i = 0; i < M; i ++){
        cin >> vecU[i] >> vecV[i] >> vecC[i];
    }
    vecUtoV.resize(N + 1);
    for(ll i = 0; i < M; i ++){
        vector<ll> vecVC(2);
        vecVC[0] = vecV[i];
        vecVC[1] = vecC[i];
        vecUtoV[vecU[i]].push_back(vecVC);
    }
    searched.resize(L + 1);
    vl v0 = {1, 0};
    searched[0].push_back(v0);
    for(ll i = 0; i < L; i ++){
        search(i);
    }

    vvl resultL = searched[L];
    vl result;
    for(ll i = 0; i < resultL.size(); i ++){
        ll cost = resultL[i][1];
        if(cost >= S && cost <= T){
            result.push_back(resultL[i][0]);
        }
    }
    sort(result.begin(), result.end());
    ll before = 0;
    for(ll i = 0; i < result.size(); i ++){
        if(result[i] != before){
            before = result[i];
            cout << before << " ";
        }
    }
    cout << endl;
    // ll l = 1;
    // for(ll i = 0; i < searched[l].size(); i ++){
    //     cout << searched[l][i][0] << " " << searched[l][i][1] << endl;
    // }

    // for(ll i = 0; i < 2; i ++){
    //     cout << vecUtoV[1][i][0] << endl;
    // }
    

    
}