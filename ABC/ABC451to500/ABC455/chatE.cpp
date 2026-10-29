#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


ll N;
string S;
int main(){
    cin >> N >> S;
    vl vecA(N + 1, 0), vecB(N + 1, 0), vecC(N + 1, 0);
    vl vecAB(N + 1), vecBC(N + 1), vecCA(N + 1), vecABC(N + 1);
    ll a = 0, b = 0, c = 0;
    
    for(ll i = 0; i < N; i ++){
        if(S[i] == 'A'){
            a ++;
        }
        if(S[i] == 'B'){
            b ++;
        }
        if(S[i] == 'C'){
            c ++;
        }
        vecA[i + 1] = a;
        vecB[i + 1] = b;
        vecC[i + 1] = c;
    }
    for(ll i = 0; i <= N; i ++){
        vecAB[i] = vecA[i] - vecB[i];
        vecBC[i] = vecB[i] - vecC[i];
        vecCA[i] = vecC[i] - vecA[i];
        vecABC[i] = N * vecA[i] - (N - 1) * vecB[i] - vecC[i];
    }
    unordered_map<ll, ll> mapAB, mapBC, mapCA, mapABC;
    for(ll i = 0; i <= N; i ++){
        mapAB[vecAB[i]] ++;
        mapBC[vecBC[i]] ++;
        mapCA[vecCA[i]] ++;
        // cout << "vecCA: " << vecCA[i] << endl;
        mapABC[vecABC[i]] ++;
    }
    vector<unordered_map<ll, ll>> maps = {mapAB, mapBC, mapCA, mapABC};
    vector<ll>results(4);
    ll k, q;
    for(ll i = 0; i < 4; i ++){
        for(auto &p: maps[i]){
            // if(i == 2){
            //     cout << "p: " << p.first << " " << p.second << endl;
            // }
            if(p.second >= 2){
                results[i] += p.second * (p.second - 1) / 2;
            }
        }
    }
    ll total = N * (N + 1) / 2;
    cout << total << endl;
    for(ll i = 0; i < 3; i ++){
        total -= results[i];
        cout << total << endl;
    }
    total += results[3] * 2;

    cout << total << endl;  
}