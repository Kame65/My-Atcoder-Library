#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll N, K;
vl vecA;

int main(){
    cin >> N >> K;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N; i ++){
        vecA[i]  = vecA[i] % K;
    }
    sort(vecA.begin(), vecA.end());
    vecA.push_back(vecA[0] + K);
    ll max = 0;
    for(ll i = 0; i < N; i ++){
        ll len = vecA[i + 1] - vecA[i];
        if(len > max){
            max = len;
        }
    }

    cout << K - max << endl;
}