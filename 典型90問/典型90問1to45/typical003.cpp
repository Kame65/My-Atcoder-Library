#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
using ll = long long int;

ll N;
vector<ll> vecA, vecB;
vector<ll> lenV;
vector<vector<ll>> loads;

vector<ll> distances;
vector<bool> check;

ll getWay(ll start, ll distance){// startからの再長距離を探索
    check[start] = true;
    ll maxDis = 0;
    distances[start] = distance;

    for(ll i = 0; i < loads[start].size(); i ++){
        ll nextV = loads[start][i];
        if(check[nextV]){
            continue;
        }
        ll dis = 1 + getWay(nextV, distance + 1);
        if(dis > maxDis){
            maxDis = dis;
        }
    }
    
    // cout << "start = " << start << " " << maxDis << endl;
    return maxDis;


}
int main(){
    cin >> N;
    vecA.resize(N);
    vecB.resize(N);
    loads.resize(N + 1);
    for(ll i = 0; i < N - 1; i ++){
        cin >> vecA[i] >> vecB[i];
    }

    for(ll i = 0; i < N; i ++){
        loads[vecA[i]].push_back(vecB[i]);
        loads[vecB[i]].push_back(vecA[i]);
    }

    distances.resize(N + 1, -1);
    check.resize(N + 1, false);
    getWay(1, 0);
    ll maxDis = 0;
    ll idx = 0;
    for(ll i = 0; i <= N; i ++){
        // cout << i << ", " << distances[i] << endl;
        if(distances[i] > maxDis){
            idx = i;
            maxDis = distances[i];
        }
    }
    // cout << maxDis << endl;

    fill(check.begin(), check.end(), false);

    cout << getWay(idx, 0) + 1 << endl;

}