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
    ll N;
    cin >> N;
    vl vecA(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    vl res(3, 0);
    for(ll i = 0; i < N; i ++){
        ll rem = (1000 - (vecA[i] % 1000)) % 1000;
        // cout << rem << endl;

        res[2] += rem / 100;
        rem %= 100;
        res[1] += rem / 10;
        rem %= 10;
        res[0] += rem;
        
        

    }

    for(ll i = 0; i < 3; i ++){
        cout << res[i] << " ";
    }
    cout << endl;
}
