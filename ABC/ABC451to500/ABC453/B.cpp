#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long int;
using vl = vector<ll>;

ll T, X;
vl vecA, times, vals;

int main(){
    cin >> T >> X;
    vecA.resize(T + 1);
    
    for(ll i = 0; i <= T; i ++){
        cin >> vecA[i];
    }
    ll before = vecA[0];
    times.push_back(0);
    vals.push_back(vecA[0]);
    for(ll i = 1; i <= T; i ++){
        if(abs(before - vecA[i]) >= X){
            times.push_back(i);
            vals.push_back(vecA[i]);
            before = vecA[i];
        }
        
    }
    for(ll i = 0; i < times.size(); i ++){
        cout << times[i] << " " << vals[i] << endl;
    }
}