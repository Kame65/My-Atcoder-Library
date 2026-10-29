#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> vecS(N), vecT(M);
    for(ll i = 0; i < N; i ++){
        cin >> vecS[i];
    }
    for(ll i = 0; i < M; i ++){
        cin >> vecT[i];
    }
    vector<map<char, vector<ll>>> idxMap(10);
    for(ll i = 0; i < N; i ++){
        for(int j = 0; j < vecS[i].size(); j ++){
            idxMap[j][vecS[i][j]].push_back(i);
        }
    }
    vl ans(N, 0);
    for(ll i = 0; i < M; i ++){
        vl res(N, 0);
        for(ll j = 0; j < vecT[i].size(); j ++){
            // cerr << "vecT[" << i << "][" << j << "] = " << vecT[i][j] << endl;
            for(int v: idxMap[j][vecT[i][j]]){
                // cout << "add" << v << endl;
                res[v] ++;
            }
        }
        ll near = 0;
        ll nearNum = -1;
        ll pefNum = -1;
        for(int j = 0; j < N; j ++){


            if(res[j] == vecT[i].size() - 1 && vecS[j].size() == vecT[i].size()){
                // cerr << "near " << i << endl;
                near ++;
                nearNum = j;
            }
            if(vecS[j].size() == vecT[i].size() && res[j] == vecT[i].size()){
                // cerr << "perfect" << endl;
                pefNum = j;
            }
        }
        // cout << pefNum << " " << near << " " << nearNum << endl;
        if(pefNum >= 0){
            ans[pefNum] ++;
        }
        else if(near == 1){
            ans[nearNum] ++;
        }

    }
    for(ll i = 0; i < N; i ++){
        cout << ans[i] << endl;
    }



}