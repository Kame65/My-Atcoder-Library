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
    ll N, T;
    cin >> N >> T;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll total = 0;
    ll openTime = 0;
    bool open = true;
    for(ll i = 0; i < N; i ++){
        if(vecA[i] > openTime){
            total += vecA[i] - openTime;
            openTime = vecA[i] + 100;
        }
    }
    if(T > openTime){
        total += T - openTime;
    }

    cout << total << endl;
}