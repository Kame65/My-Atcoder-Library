#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

int main(){
    ll N, K;
    cin >> N >> K;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    multiset<ll> search;
    bool minOK = false, maxOK = false;
    vector<bool> upL(N, false), upR(N, false);

    upL[0] = true;
    upR[N - 1] = true;
    for(ll i = 1; i < N; i ++){
        if(vecA[i] >= vecA[i - 1]){
            upL[i] = true;
        }else{
            break;
        }
    }
    for(ll i = N - 2; i >= 0; i --){
        if(vecA[i] <= vecA[i + 1]){
            upR[i] = true;
        }else{
            break;
        }
        
    }
    // for(ll i = 0; i < N; i ++){
    //     cout << upL[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < K; i ++){
        search.insert(vecA[i]);
    }
    ll e = K - 1;
    bool ans = false;
    for(ll s = 0; s < N - K + 1; s ++){
        bool first = false;
        bool second = false;
        // cout << s << " " << e << endl;
        // cout << *search.begin() << endl;
        // cout << *search.rbegin() << endl;

        if(s != 0){
            if(*search.begin() >= vecA[s - 1] && upL[s - 1]){
                first = true;
            }
        }else{
            first = true;
        }
        if(e != N - 1){
            if(*search.rbegin() <= vecA[e + 1] && upR[e+1]){
                second = true;
            }
        }else{
            second = true;
        }
        if(first && second){
            ans = true;
            // break;
        }
        e ++;
        search.insert(vecA[e]);
        auto iter = search.find(vecA[s]);
        search.erase(iter);

    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}
