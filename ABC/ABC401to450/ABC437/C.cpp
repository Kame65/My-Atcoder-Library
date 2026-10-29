#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
using ll = long long int;

ll T;

ll solve(ll N){
    vector<vector<ll>> vecWP(N, vector<ll>(3));

    ll totalWeight = 0;
    for(ll i = 0; i < N; i ++){
        cin >> vecWP[i][0] >> vecWP[i][1];
        vecWP[i][2] = vecWP[i][0] + vecWP[i][1];
        totalWeight += vecWP[i][0];
    }
    sort(vecWP.begin(),vecWP.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[2] < beta[2];});
    ll result = N;
    for(ll i = N - 1; i >= 0; i --){
        // cout << "result: " << result << ", total: " << totalWeight << endl;
        if(totalWeight <= 0){
            return result;
        }else{
            totalWeight -= vecWP[i][2];
            result --;
        }
    }
    return 0;



}

int main(){
    cin >> T;
    for(int i = 0; i < T; i ++){
        ll N;
        cin >> N;
        ll result = solve(N);
        cout << result << endl;
    }
}