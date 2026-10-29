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
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> vecX(N);
    for(ll i = 0; i < N; i ++){
        ll x;
        cin >> x;
        vecX[i] = make_pair(x, i + 1);
    }
    sort(vecX.begin(), vecX.end());
    vl res;

    if(vecX[1].first - vecX[0].first >= D){
        res.push_back(vecX[0].second);
    }
    if(vecX[N - 1].first - vecX[N - 2].first >= D){
        res.push_back(vecX[N - 1].second);
    }

    for(ll i = 1; i < N - 1; i ++){
        if(vecX[i].first - vecX[i - 1].first >= D && vecX[i + 1].first - vecX[i].first >= D){
            res.push_back(vecX[i].second);
        }
    }
    cout << res.size() << endl;;
    sort(res.begin(), res.end());
    for(ll i = 0; i < res.size(); i ++){
        cout << res[i] << " ";
    }
    cout << endl;
    
}
