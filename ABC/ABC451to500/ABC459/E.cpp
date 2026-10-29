#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;



ll N;
vl vecP, vecC, vecD;
vvl vecSon;

ll search(ll n){
    ll ans = 0;
    for(ll i = 0; i < vecSon[n].size(); i ++){
        ans += search(vecSon[n][i]);
    }
    ans += 
}


int main(){

    cin >> N;
    vecP = vl(N + 1);
    vecC = vl(N + 1);
    vecD = vl(N + 1);
    vecSon = vvl(N + 1, vl());
    for(ll i = 2; i <= N; i ++){
        cin >> vecP[i];
        vecSon[vecP[i]].push_back(i);
    }
    for(ll i = 1; i <= N; i ++){
        cin >> vecC[i];
    }
    for(ll i = 1; i <= N; i ++){
        cin >> vecD[i];
    }


    

    



}