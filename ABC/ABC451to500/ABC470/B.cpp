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

int main(){
    ll N;
    cin >> N;
    vl vecC(N + 1, 0);
    unordered_map<ll, ll> used;
    ll ans = 0;
    ll largest = 0;

    for(ll i = 0; i < N; i ++){
        ll c;
        cin >> c;
        vecC[c] ++;
        if(vecC[c] > largest){
            largest = vecC[c];
        }

    }

    cout << N - largest << endl;

    
}