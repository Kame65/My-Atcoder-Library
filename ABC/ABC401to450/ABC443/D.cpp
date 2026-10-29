#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



ll up(ll N, ll idx,  vl& vecR, vector<bool>& memo, vvl& points){//idx+-1をあげる
    ll nIdx = idx + 1;
    ll num = vecR[idx];
    ll total = 0;
    ll bIdx = idx - 1;
    if(memo[idx]){
        return 0;
    }

    if(bIdx >= 0){
        // cout << "bIdx " << bIdx << endl;
        if(vecR[bIdx] > num + 1){
            total += vecR[bIdx] - num - 1;
            vecR[bIdx] = num + 1;
            points[num + 1].push_back(bIdx);
        }
    }
    // cout << idx << endl;
    if(nIdx < N){
        // cout << "nIdx " << nIdx << endl;
        if(vecR[nIdx] > num + 1){
            total += vecR[nIdx] - num - 1;
            vecR[nIdx] = num + 1;
            points[num + 1].push_back(nIdx);
        }
    }
    memo[idx] = true;
    return total;
}
void solveCase(){
    ll N;
    cin >> N;
    vl vecR(N);
    vvl points(N + 1);
    for(ll i = 0; i < N; i ++){
        cin >> vecR[i];
        points[vecR[i]].push_back(i);
    }
    // sort(vecSortR.begin(),vecSortR.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});
    ll total = 0;
    vector<bool> memo(N, false);
    for(ll i = 0; i <= N; i ++){
        // cout << points[j].size() << endl;
        for(ll j = 0; j < points[i].size(); j ++){
            total += up(N, points[i][j] ,vecR, memo, points);
        }

    }
    cout << total << endl;
    
}
    

        


int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }

}