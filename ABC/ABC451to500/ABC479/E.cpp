#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    
    vvl edges(N + 1);
    vl vecA(N);
    vl vecB(N);
    for(ll i = 0; i < N - 1; i ++){
        ll a, b;
        cin >> a >> b;
        vecA[i] = a;
        vecB[i] = b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vl par(N + 1, -1);
    par[1] = 0;
    ll beforeV = 1;
    vl stack;
    vl hasV(N + 1, 0);
    vvl depthV(N);
    vl depth(N + 1, -1);
    depth[1] = 0;

    depthV[0].push_back(1);
    // cerr << "OK1" << endl;
    stack.push_back(beforeV);
    while(stack.size() > 0){
        beforeV = stack.back();
        stack.pop_back();
        // cerr << beforeV << endl;
        for(ll v: edges[beforeV]){
            if(par[v] >= 0) continue;
            par[v] = beforeV;
            depth[v] = depth[beforeV] + 1;
            depthV[depth[v]].push_back(v);
            stack.push_back(v);
        }
    }
    for(ll i = N - 1; i >= 0; i --){
        for(ll v: depthV[i]){
            hasV[v] ++;
            hasV[par[v]] += hasV[v];
        }
    }
    cerr << "res: " << endl;
    for(ll i = 1; i <= N; i ++){
        cerr << hasV[i] << endl;
    }
    vl result(N + 1, 0);
    for(ll i = 0; i < N - 1; i ++){
        ll a = vecA[i];
        ll b = vecB[i];
        if(hasV[a] > hasV[b]){
            if(hasV[b] > N / 2){//bの方が大きい
                result[b] += i + 1;
            }else{
                result[b] -= i + 1;
                result[1] += i + 1;
            }
        }else{
            if(hasV[a] > N / 2){
                result[a] += i + 1;
            }else{
                result[a] -= i + 1;
                result[1] += i + 1;
            }
        }
        cerr << i + 1 << " " << result[1] << endl;
    }
    stack.push_back(1);
    cerr << "OK3" << endl;
    vector<bool> already(N + 1, false);
    while(stack.size() > 0){
        beforeV = stack.back();
        stack.pop_back();
        already[beforeV] = true;
        // cerr << beforeV << endl;
        for(ll v: edges[beforeV]){
            if(already[v]) continue;
            result[v] += result[par[v]];
            stack.push_back(v);
        }
    }
    for(ll i = 1; i <= N; i ++){
        cout << result[i] << " ";
    }
    cout << endl;
    
}