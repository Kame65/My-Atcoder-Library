#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, M;
    cin >> N >> M;
    vl vecX(M);
    for(ll i = 0; i < M; i ++){
        cin >> vecX[i];
    }
    vl result(2 * N + 1, 0);
    ll allDefaultCost = 0;
    for(ll i = 1; i < M; i ++){
        ll v = vecX[i - 1];
        ll u = vecX[i];
        ll defaultCost, cost;
        // cout << "u = " << u << ", v = " << v << endl;

        

        if(abs(u - v) > N - (abs(u - v))){
            defaultCost = N - abs(u - v);
            allDefaultCost += defaultCost;
            cost = abs(u - v) - (N - (abs(u - v)));
            if(u > v){
                ll temp = u;
                u = v;
                v = temp;

            }
            result[v] += cost;
            result[N + u] -= cost;
            // cout << "s: " << u << " v: " << v << endl;

        }else{
            defaultCost = abs(u - v);
            allDefaultCost += defaultCost;
            cost = (N - (abs(u - v))) - abs(u - v);
            if(u > v){
                ll temp = u;
                u = v;
                v = temp;

            }
            // cout << "s: " << v << " g: " << N + u << endl;
            result[u] += cost;
            result[v] -= cost;

        }
        // cout << "i = " << i << " defCost: " << defaultCost << "u, v = " << u << " " << v << endl;

    }

    // cout << "result[i]" << endl;
    // for(ll i = 0; i < result.size(); i ++){
    //     cout << result[i] << endl;
    // }
    vl lastResult(N, 0);
    for(ll i = 1; i < 2 * N + 1; i ++){
        result[i] = result[i - 1] + result[i];
    }
    for(ll i = 0; i < 2 * N; i ++){
        lastResult[i % N] += result[i];
    }
    ll minCost = lastResult[0];
    for(ll i = 0; i < N; i ++){ 
        // cout << "lastResult: " << i << ", " << lastResult[i] << endl;
        if(minCost > lastResult[i]){
            minCost = lastResult[i];
        }
        // cout << "lastResult: " << i << " " << lastResult[i] << endl;
    }
    // cout << "all default Cost = " << allDefaultCost << endl;
    // cout << minCost << endl;
    cout << allDefaultCost + minCost << endl;

}
