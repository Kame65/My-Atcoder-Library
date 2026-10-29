#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long int;
using namespace std;

ll myPow(ll a, ll n){
    ll result = 1;
    for(ll i = 0; i < n; i ++){
        result *= a;
    }
    return result;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a < myPow(c, b)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
