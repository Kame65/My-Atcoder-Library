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
    ll N, M;
    cin >> N >> M;
    vl ans(N, 0);
    for(ll i = 0; i < M; i ++){
        ans[i % N] ++;
    }
    for(int i = 0; i < N; i ++){
        cout << ans[i] << endl;
    }

}
