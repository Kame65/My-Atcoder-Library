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



int main(){
    ll N, K, X;
    cin >> N >> K >> X;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    sort(vecA.begin(), vecA.end());
    ll total = 0;
    ll cnt = 0;
    for(ll i = K - 1; i >= 0; i --){
        // cout << "vecA[i] = " << vecA[i] << endl;
        total += vecA[i];
        cnt ++;
        
        // cout << "total = " << total << endl;
        if(total >= X){
            cout << N - K + cnt << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}