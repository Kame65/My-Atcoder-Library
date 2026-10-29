#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


ll N, C;
int main(){
    cin >> N;
    vector<vector<ll>> vecCs(2, vector<ll>(N + 1, 0));
    vector<vector<ll>> totals(2, vector<ll>(N + 1, 0));
    for(ll i = 1; i <= N; i ++){
        int c, p;
        cin >> c >> p;
        vecCs[c - 1][i] = p;
    }
    for(ll c = 0; c < 2; c ++){
        for(ll i = 1; i <= N; i ++){
            totals[c][i] = totals[c][i - 1] + vecCs[c][i];
        }
    }
    ll Q;
    cin >> Q;
    vector<ll> vecL(Q), vecR(Q);
    for(ll i = 0; i < Q; i ++){
        ll l, r;
        cin >> vecL[i] >> vecR[i];
    }
    for(ll i = 0; i < Q; i ++){
        cout << totals[0][vecR[i]] - totals[0][vecL[i] - 1]
         << " " << totals[1][vecR[i]] - totals[1][vecL[i] - 1]
          << endl;
    }
}