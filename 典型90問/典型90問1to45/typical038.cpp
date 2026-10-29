#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;
using ll = long long int;
using vl = vector<ll>;

int main(){
    ll A, B;
    cin >> A >> B;
    ll numGcd = gcd(A, B);


    ll ans = A / numGcd * B;
    
    if(A / numGcd > (ll)1e18 / B){
        cout << "Large" << endl;
    }else{
        cout << ans << endl;
    }
}