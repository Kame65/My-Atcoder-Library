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


ll N, M;
vvl sToE, eToS;
vl sPlus, ePlus;

bool judge(ll s, ll t){
    // cout << "judge: " << s << ", " << t << endl;
    if(sToE[s].size() == 0 || eToS[t].size() == 0){
        return false;
    }
    // cout << "Ok1" << endl;
    auto itersV = upper_bound(sToE[s].begin(), sToE[s].end(), t);
    if(itersV == sToE[s].begin()){
        return false;
    }
    // cout << "Ok2" << endl;
    ll sV = sToE[s][itersV - sToE[s].begin() - 1];
    // cout << "idx: " << itersV - sToE[s].begin() - 1 << endl;

    // for(ll i = 0; i < sToE[s].size(); i ++){
    //     cout << sToE[s][i] << endl;
    // }
    auto itereV = lower_bound(eToS[t].begin(), eToS[t].end(), s);
    if(itereV == eToS[t].end()){
        return false;
    }
    // cout << "Ok3" << endl;
    ll eV = *itereV;
    // cout << sV + 1 << ", " << eV << endl;
    // cout << s << ", " << sV << ", " << t << ", " << eV << endl;
    if(sV + 1 >= eV){
        // cout << "t: ";
        // cout << ", " << ePlus[t] << endl;
        
        if(sPlus[s] < t || ePlus[t] > s){
            return true;
        }
        // cout << sV << ", " << *itereV << endl;
        if(eV == s && t == sV){
            ll idx = itereV - eToS[t].begin();
            if(eToS[t].size() > idx && eToS[t][idx + 1] == s){
                return true;
            }
        }
    }
    return false;


}

int main(){
    cin >> N >> M;
    sToE = vvl(N + 1);
    eToS = vvl(N + 1);
    sPlus = vl(N + 1, N + 1);
    ePlus = vl(N + 1, 0);
    for(ll i = 0; i < M; i ++){
        ll l, r;
        cin >> l >> r;
        sToE[l].push_back(r);
        eToS[r].push_back(l);
        if(sPlus[l] > r){
            sPlus[l] = r;
        }
        if(ePlus[r] < l){
            ePlus[r] = l;
        }
    }
    ll beforeS = N + 1;
    
    for(ll i = N; i > 0; i --){
        if(sPlus[i] > beforeS){
            sPlus[i] = beforeS;
        }
        beforeS = sPlus[i];
        // cout << sPlus[i] << " ";
    }
    // cout << "sPlus[1] = " << sPlus[1] << endl;
    ll beforeE = 0;
    for(ll i = 1; i <= N; i ++){
        if(ePlus[i] < beforeE){
            ePlus[i] = beforeE;
        }
        beforeE = ePlus[i];
    }

    for(ll i = 1; i <= N; i ++){
        sort(sToE[i].begin(), sToE[i].end());
        sort(eToS[i].begin(), eToS[i].end());
    }
    

    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i ++){
        ll s, t;
        cin >> s >> t;
        if(judge(s, t)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}