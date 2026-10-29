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

    vvl receive = vvl(N + 1, vl());
    for(ll i = 0; i < N; i ++){
        ll K;
        cin >> K;
        for(ll j = 0; j < K; j ++){
            ll a;
            cin >> a;
            receive[a].push_back(i + 1);
        }
    }

    for(ll i = 1; i <= N; i ++){
        cout << receive[i].size() << " ";
        for(ll j = 0; j < receive[i].size(); j ++){
            cout << receive[i][j] << " ";
        }
        cout << endl;
    }
    

}