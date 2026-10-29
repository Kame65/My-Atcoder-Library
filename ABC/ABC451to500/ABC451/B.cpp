#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long int;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> before(M), after(M);
    before.resize(M, 0);
    after.resize(M, 0);
    for(ll i = 0; i < N; i ++){
        ll a, b;
        cin >> a >>  b;
        before[a - 1] += 1;
        after[b - 1] += 1;
    }
    for(ll i = 0; i < M; i ++){ 
        cout << after[i] - before[i] << endl;
    }
}