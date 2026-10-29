#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

ll N;
vector<ll> vecA;
ll f(ll n);

ll getA(ll n){
    
    if(vecA[n] > 0){
        return vecA[n];
    }
    ll result = 0;
    for(ll i = 0; i < n; i ++){
        result += f(getA(i));
    }
    vecA[n] = result;
    // cout << n << ", " << result << endl;
    return result;
}

ll f(ll n){
    ll result = 0;
    while(n > 0){
        result += n % 10;
        n /= 10;
    }
    return result;

}



int main(){
    cin >> N;
    vecA.resize(N + 2, -1);
    vecA[0] = 1;
    cout << getA(N) << endl;

}
