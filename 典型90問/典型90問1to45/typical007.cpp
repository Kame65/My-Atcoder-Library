#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;



int main(){
    ll N;
    cin >> N;
    vector<ll>vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    sort(vecA.begin(), vecA.end());
    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i ++){
        ll b;
        cin >> b;
        auto iter = lower_bound(vecA.begin(), vecA.end(), b);
        if(iter == vecA.end()){
            cout << abs(vecA[N - 1] - b) << endl;
        }else{
            ll idx = iter - vecA.begin();
            if(idx == 0){
                cout << abs(vecA[idx] - b) << endl;
            }else{
                cout << min(abs(vecA[idx] - b), abs(vecA[idx - 1] - b)) << endl;
            }
        }   
    }
}