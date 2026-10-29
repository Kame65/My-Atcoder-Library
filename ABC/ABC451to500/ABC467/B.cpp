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
    ll N, A, B;
    string S;
    ll ans = 0;
    cin >> N;
    for(ll i = 0; i < N; i ++){
        cin >> A >> B >> S;
        if(S == "keep"){
            ans += B - A;
        }

    }
    cout << ans << endl;
}