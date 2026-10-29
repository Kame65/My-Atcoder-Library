#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;


int main(){
    ll N;
    cin >> N;
    vector<vl>vecLH(N, vl(2));
    for(ll i = 0; i < N; i ++){
        cin >> vecLH[i][1] >> vecLH[i][0]; 
    }

    //Lの大きい順
    sort(vecLH.begin(),vecLH.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[0] > beta[0];});
    ll max = 0;
    vvl vecSort;
    for(ll i = 0; i < N; i ++){
        if(vecLH[i][1] > max){
            max = vecLH[i][1];
            vecSort.push_back(vecLH[i]);
        }
    }
    sort(vecSort.begin(),vecSort.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[0] < beta[0];});
    
    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i ++){
        
    }
}