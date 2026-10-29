#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


ll N;
vector<ll> vecA;

bool judge(ll cnd){
    ll l = 0, r = N - 1;
    while(r - l >= 0){
        if(vecA[r] == cnd){
            r --;
        }else if(l == r){
            return false;
        }else if(vecA[l] + vecA[r] == cnd){
            l ++;
            r --;
        }else{
            return false;
        }
        // cout << l << ", " << r << endl;
    }
    return true;
}

int main(){
    cin >> N;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }    
    sort(vecA.begin(), vecA.end());
    vector<ll> inds;
    vector<ll> cnds;
    cnds.push_back(vecA[0] + vecA[N - 1]);
    cnds.push_back(vecA[N - 1]);
    for(ll i = 1; i >= 0; i --){
        if(judge(cnds[i])){
            cout << cnds[i] << " ";
        }
    }
    cout << endl;

}