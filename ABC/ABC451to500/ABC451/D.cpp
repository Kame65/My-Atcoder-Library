#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>


using namespace std;
using ll = long long int;

vector<ll> P;
set<ll> results;

void getResult(ll num){
    if(num > 1e9){
        return;
    }
    // cout << num << endl;
    for(ll i = 0; i < P.size(); i ++){
        ll oneP = P[i];
        int size = to_string(oneP).size();
        results.insert(num * pow(10, size) + oneP);
        ll nextNum = num * pow(10, size) + oneP;
        if(nextNum > 1e9){
            break;
        }
        getResult(nextNum);
    }
}

int main(){
    ll N;
    cin >> N;
    ll i = 0;
    while(true){
        ll num = pow(2ll, i);
        // cout << num << endl;
        if(num > 1e9){
            break;
        }
        P.push_back(num);
        i ++;
    }
    // cout << "P is OK" << endl;
    getResult(0);

    auto it = next(results.begin(), N - 1);
    cout << *it << endl;

    
}