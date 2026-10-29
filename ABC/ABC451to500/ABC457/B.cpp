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
    vvl vecA(N + 1);
    for(ll x = 1; x <= N; x ++){
        ll L;
        cin >> L;
        vecA[x] = vl(L + 1);
        for(ll y = 1; y <= L; y ++){
            cin >> vecA[x][y];
        }
    }

    ll X, Y;
    cin >> X >> Y;
    cout << vecA[X][Y] << endl;
}