#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using ll = long long int;


vector<ll> vec;
vector<vector<ll>> vecl;

int main(){
    ll D, F;
    cin >> D >> F;
    while(true){
        if(F > D){
            break;
        }else{
            F += 7;
        }
    }
    cout << F - D << endl;

}