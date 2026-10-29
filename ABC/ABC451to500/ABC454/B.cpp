#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using ll = long long int;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, M;
    cin >> N >> M;
    bool result1 = true, result2 = true;;

    vl vecM(M + 1, 0);
    for(ll i = 0; i < N; i ++){
        ll f;
        cin >> f;
        vecM[f] ++;
        if(vecM[f] > 1){
            result1 = false;
        }
    }
    for(ll i = 1; i <= M; i ++){
        if(vecM[i] == 0){
            result2 = false;
        }
    }
    if(result1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    if(result2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}