#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

vvl edges;

bool findRoute(ll u, ll v, vl& res, vector<bool>& done){
    if(done[u]){
        return false;
    }
    done[u] = true;
    if(u == v){
        res.push_back(u);
        return true;
    }
    for(ll i = 0; i < edges[u].size(); i ++){
        if(findRoute(edges[u][i], v, res, done)){
            res.push_back(u);
            return true;
        }
    }
    return false;
}
ll culcMax(vl& res){
    
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vl vecH(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecH[i];
    }
    edges = vvl(N + 1);
    for(ll i = 2; i <= N; i ++){
        ll p;
        cin >> p;
        edges[i].push_back(p);
        edges[p].push_back(i);
    }
    
    for(ll i = 0; i < Q; i ++){
        vl res;
        ll u, v;
        cin >> u >> v;
        vector<bool>done(N + 1);
        findRoute(u, v, res, done);
        ll ans = 1;
        ll max = 1;
        // cout << "res " << endl;
        // cout << res[0] << " ";
        for(ll i = 1; i < res.size(); i ++){// 後ろの点から入っている
            // cout << res[i] << " ";
            // cout << "comp: " << vecH[res[i - 1]] << " " << vecH[res[i]] << endl;
            if(vecH[res[i - 1]] < vecH[res[i]]){
                max ++;
            }else{
                if(ans < max){
                    ans = max;
                }
                max = 1;
            }
            // cout << "max = " << max << endl;
            
        }
        if(max > ans){
            ans = max;
        }
        // cout << endl;
        // cout << "ans: " << endl;
        cout << ans << endl;


        
    }
}