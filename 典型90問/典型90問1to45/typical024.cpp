#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll>vecA(N), vecB(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N; i ++){
        cin >> vecB[i];
    }
    ll cnt = 0;
    for(ll i = 0; i < N; i ++){
        cnt += abs(vecA[i] - vecB[i]);
    }
    // cout << "cnt = " << cnt << endl;
    if(K >= cnt && (K - cnt) % 2 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}