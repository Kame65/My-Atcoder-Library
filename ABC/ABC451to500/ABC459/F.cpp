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


void solveCase(){
    ll N;
    cin >> N;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    vl vecDif(N - 1);
    for(ll i = 0; i < N - 1; i ++){
        vecDif[i] = vecA[i + 1] - vecA[i];
    }
    ll idx = 0;
    ll res = 0;
    while(true){
        // cout << "idx = " <<idx << ": " << res << endl;

        // for(int i = 0; i < N - 1; i ++){
        //     cout << vecDif[i] << " ";
        // }
                
        if(idx == N - 1){
            cout << res << endl;
            return;
        }
        // cout << endl;
        if(vecDif[idx] <= 0){
            ll pls = - (vecDif[idx] / 2) + 1;
            vecDif[idx] += pls * 2;
            res += pls;
            if(idx != 0){
                vecDif[idx - 1] -= pls;
            }
            if(idx != N - 2){
                vecDif[idx + 1] -= pls;
            }
            idx --;
        }else{
            idx ++;
        }
        if(idx < 0){
            idx ++;
        }

    }
}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}