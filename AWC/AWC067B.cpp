#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;



ll N;
vl vecA, maxs, maxK;
int main(){
    cin >> N;
    vecA = vl(N);
    maxs =vl(N);
    maxK = vl(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll before = 0;
    for(ll i = 0; i < N; i ++){
        if(i == 0){
            maxK[i] = vecA[i];
            maxs[i] = vecA[i];
            // cout << "vA[i] = " << vecA[i] << endl;
        }else{
            maxK[i] = max(maxK[i - 1] + vecA[i], vecA[i]);
            maxs[i] = max(maxK[i], maxs[i - 1]);
        }

        // cout << "K: " << maxK[i] << endl;
        cout << maxs[i] << endl;
    }


}