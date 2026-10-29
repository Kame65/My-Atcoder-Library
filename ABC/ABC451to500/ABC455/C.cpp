#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

int main(){
    ll N, K;
    cin >> N >> K;
    set<ll> setA;
    unordered_map<ll, ll> memo;
    priority_queue<ll> results;
    for(ll i = 0; i < N; i ++){
        ll a;
        
        cin >> a;
        setA.insert(a);
        memo[a] += a;
    }
    for(ll i: setA){
        results.push(memo[i]);
    }

    for(ll i = 0; i < K; i ++){
        // cout << "pop: " << results.top() << endl;
        results.pop();

        if(results.size() == 0){
            break;;
        }
    }
    ll ans = 0;
    // cout << results.size() << endl;
    while (results.size() > 0){
        ans += results.top();
        // cout << results.top() << endl;;
        results.pop();
    }

    cout << ans << endl;
}