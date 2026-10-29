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
    vl vecHi(1e6, 0);
    vl vecTotal(1e6, 0);
    vecHi[0] = N;
    vecTotal[0] = N;
    ll minusCnt = 0;
    for(ll i = 0; i < Q; i ++){
        ll q, xy;
        cin >> q >> xy;
        // cout << "minusCnt = " << minusCnt << endl;
        if(q == 1){
            ll height = vecHi[xy];
            vecHi[xy] ++;
            vecTotal[height + 1] ++;
            if(vecTotal[height + 1] == N){
                // cout << "minus" << endl;
                minusCnt ++;
            }
        }else{

            // cout << minusCnt << endl;
            
            cout << vecTotal[xy + minusCnt] << endl;
        }
    }
}