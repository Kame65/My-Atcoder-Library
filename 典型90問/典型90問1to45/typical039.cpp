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

vvl edges;
vl depth;

vl merge(ll cv){//aより下をmerge
    // cerr << "merge" << cv << "\n";
    vl cInfo;
    ll csizeV = 1;
    ll cdist = 0;
    ll cres = 0;

    for(ll nv: edges[cv]){
        if(depth[nv] < depth[cv])continue;
        auto ninfo = merge(nv);
        ll nsizeV = ninfo[0];
        ll ndist = ninfo[1];
        ll nres = ninfo[2];
        ll sizeV = csizeV + nsizeV;
        ll dist = nsizeV + cdist + ndist;
        ll res = csizeV * nsizeV + csizeV * ndist + nsizeV * cdist + cres + nres;
        // cerr << "mergeA: " << csizeV << " " << cdist << " " << cres << "\n";
        // cerr << "mergeB: " << nsizeV << " " << ndist << " " << nres << "\n";
        csizeV = sizeV;
        cdist = dist;
        cres = res;
        // cerr << "merged: " << csizeV << " " << cdist << " " << cres << "\n";
    }
    return {csizeV, cdist, cres};
}

int main(){
    ll N; cin >> N;
    edges = vvl(N + 1);
    for(ll i = 0; i < N - 1; i ++){
        ll a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    depth = vl(N + 1, -1);
    queue<vl> q;
    q.push({1, 0});
    while(q.size() > 0){
        auto now = q.front();
        ll cv = now[0];
        ll cd = now[1];//depth
        q.pop();
        for(int nv: edges[cv]){
            if(depth[nv] >= 0)continue;
            q.push({nv, cd + 1});
        }
        depth[cv] = cd;
    }
    // cerr << "init" << endl;
    // for(int i = 1; i <= N; i ++){
    //     cout << depth[i] << "\n";
    // }

    cout << merge(1)[2] << endl;



}