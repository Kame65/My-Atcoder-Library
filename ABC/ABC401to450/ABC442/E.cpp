#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vvl locs(N);
    vvl groups;
    for(ll i = 0; i < N; i ++){
        ll x, y;
        cin >> x >> y;
        long double atan = atan2l(y, x);
        
        ll atan2 = (ll)(atan * 2.86478897564 * 1e18);
        // cout << "atan2 = " << atan << endl;
        vl loc = {i + 1, x, y, atan2};


        groups.push_back(loc);
    }



    sort(groups.begin(),groups.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[3] < beta[3];});

    //sort完了
    for(ll i = 0; i < groups.size(); i ++){
        // cout << groups[i][0] << " ";
    }
    // cout << endl;
    ll before = -100;
    
    map<ll, ll> first, last;
    ll firstCnt = -1, lastCnt = 0;
    for(ll i = 0; i < groups.size(); i ++){
        if(groups[i][3] == before){
            
            first[groups[i][0]] = firstCnt;
        }else{
            firstCnt = i;
            first[groups[i][0]] = firstCnt;
        }

        before = groups[i][3];
    }
    before = 100;
    lastCnt = N;
    for(ll i = groups.size() - 1; i >= 0 ; i --){
        if(groups[i][3] == before){
            last[groups[i][0]] = lastCnt;
        }else{
            lastCnt = i + 1;
            last[groups[i][0]] = lastCnt;
        }
        // cout << groups[i][0] << ", " << last[groups[i][0]] << endl;
        before = groups[i][3];
    }

    for(ll i = 0; i < Q; i ++){
        ll A, B;
        cin >> A >> B;
        ll num = last[A] - first[B];
        // cout << "lA = " << last[A] << endl;
        // cout << "fB = " << first[B] << endl;
        if(num > 0){
            cout << num << endl;
        }else{
            cout << num + N << endl;
        }
    }
}
