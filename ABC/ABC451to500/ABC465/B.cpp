#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

int main(){
    ll X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;
    ll ans = 0;
    for(ll i = A + 1; i <= B; i ++){
        if(L < i && i <= R){
            ans += X;
        }else{
            ans += Y;
        }
    }
    cout << ans << endl;

}