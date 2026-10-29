#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long int;


int main(){
    ll N;
    cin >> N;
    vector<ll>vecA(N), vecB(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N; i ++){
        cin >> vecB[i];
    }

    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());
    ll total = 0;
    for(ll i = 0; i < N; i ++){
        // cout << vecA[i] << ", " << vecB[i] << endl;
        total += abs(vecA[i] - vecB[i]);
    }
    cout << total << endl;
}