#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;

ll N, Q;
vector<ll> vecA, noneSum;

void solveQ(){
    ll X, Y;
    cin >> X >> Y;
    ll l = 0;
    ll r = N + 1;
    if(X < vecA[0]){

    }
    while(r - l > 1){
        ll mid = (r + l) / 2;
        // cout << l << ", " << r <<", vecA[mid] = " << vecA[mid] << endl;;
        if(vecA[mid] >= X){
            r = mid;
        }else{
            l = mid;
        }
    }
    // cout << l << ", " << r << endl;
    ll underXnum = X - 1 - vecA[l] + noneSum[l];
    // lはX未満の配列にない要素の数
    ll aim = underXnum + Y;




    //aim以下の最大値

    l = 0;
    r = N + 1;
    while(r - l > 1){
        ll mid = (r + l) / 2;
        // cout << l << ", " << r <<", vecA[mid] = " << vecA[mid] << endl;;
        if(noneSum[mid] >= aim){
            r = mid;
        }else{
            l = mid;
        }
    }

    // cout << "Ai = " << vecA[l] << ", aim " << aim << endl;
    cout << vecA[l] + (aim - noneSum[l]) << endl; 

}


int main(){

    cin >> N >> Q;
    vecA.resize(N + 1, 0);
    
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    sort(vecA.begin(), vecA.end());
    noneSum.resize(N + 1);
    noneSum[0] = 0;
    for(ll i = 1; i <= N; i ++){
        noneSum[i] = vecA[i] - vecA[i - 1] + noneSum[i - 1] - 1;
    }

    for(ll i = 0; i < Q; i ++){
        solveQ();
    }
}