#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

ll N;
vector<ll> results(3 * 1e5, 0), vecA;


int main(){
    cin >> N;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N; i ++){
        results[0] += 1;
        results[vecA[i]] -= 1;
    }
    for(ll i = 1; i < results.size(); i ++){
        results[i] += results[i - 1];
    }
    ll carry = 0;
    for(ll i = 0; i < results.size(); i ++){
        results[i] += carry;
        carry = results[i] / 10;
        results[i] = results[i] % 10;
    }
    bool can = false;
    for(ll i = results.size(); i >= 0; i --){
        if(results[i] != 0){
            can = true;
        }
        if(can){
            cout << results[i];
        }
    }
    cout << endl;
}