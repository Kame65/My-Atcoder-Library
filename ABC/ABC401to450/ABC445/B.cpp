#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    
    ll N;
    cin >> N;
    vector<string> vecS(N);
    ll m = 0;
    for(ll i = 0; i < N; i ++){
        cin >> vecS[i];
        if(vecS[i].size() > m){
            m = vecS[i].size();
        }
    }

    for(ll i = 0; i < N; i ++){
        string result = "";
        ll dot = (m - vecS[i].size()) / 2;
        for(int j = 0; j < dot; j ++){
            result += ".";
        }

        result += vecS[i];
        for(int j = 0; j < dot; j ++){
            result += ".";
        }
        cout << result << endl;
    }

}