#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long int;



ll N;
vector<ll> listW, listH, listB, listMerit;
vector<vector<ll>> dp;

ll getHappy(ll n, ll w){
    if(dp[n][w] >= 0){
        return dp[n][w];
    }
    ll way1, way2;
    way1 = getHappy(n - 1, w) + listB[n];
    if(w - listW[n] * 2 >= 0){
        way2 = getHappy(n - 1, w - listW[n] * 2) + listH[n];
    }else{
        way2 = 0;
    }
    if(way1 > way2){
        dp[n][w] = way1;
    }else{
        dp[n][w] = way2;
    }
    return dp[n][w];
}

int main(){
    cin >> N;
    listW.push_back(0);
    listB.push_back(0);
    listH.push_back(0);
    for(ll i = 0; i < N; i ++){
        ll w, h, b;
        cin >> w >> h >> b;
        listW.push_back(w);
        listH.push_back(h);
        listB.push_back(b);
    }
    ll sumWeight = 0;
    for(ll i = 1; i <= N; i ++){
        sumWeight += listW[i];
    }
    dp.resize(N + 1);
    dp[0].resize(sumWeight + 1, 0);
    for(ll i = 1; i <= N; i++){
        dp[i].resize(sumWeight + 1, -1);
    }

    cout << getHappy(N, sumWeight) << endl;

}