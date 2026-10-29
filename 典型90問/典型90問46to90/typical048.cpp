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
    ll N, K;
    cin >> N >> K;
    unordered_map<ll, vl> memoBtoA;
    priority_queue<pair<ll, ll>> pQueue;
    vl vecA(N), vecB(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i] >> vecB[i];
        pQueue.push(make_pair(vecB[i], i));
    }

    ll total = 0;
    for(ll i = 0; i < K; i ++){
        ll val, idx;
        tie(val, idx) = pQueue.top();
        pQueue.pop();
        total += val;
        if(vecB[idx] == val){

            pQueue.push(make_pair(vecA[idx] - vecB[idx], i));
        }
        // cout << total << endl;
    }

    cout << total << endl;


}