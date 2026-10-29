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
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll ans = 0;
    for(ll i = 1; i < N - 1; i ++){
        if(vecA[i - 1] < vecA[i] && vecA[i] > vecA[i + 1]){
            ans ++;
        }
    }

    cout << ans << endl;
}