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
    ll N, Q;
    cin >> N >> Q;
    vl vecA = vl(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll top = 0;
    for(ll i = 0; i < Q; i ++){
        ll T, x, y;
        cin >> T >> x >> y;
        if(T == 1){
            ll preX = vecA[(top + x - 1 + N) % N];
            vecA[(top + x - 1 + N) % N] = vecA[(top + y - 1 + N) % N];
            vecA[(top + y - 1 + N) % N] = preX;
        }else if(T == 2){
            top --;
            top %= N;
        }else{
            cout << vecA[(top + x - 1 + N) % N] << endl;
        }
    }

}