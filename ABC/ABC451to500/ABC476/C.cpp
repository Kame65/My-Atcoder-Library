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
    ll N;
    cin >> N;
    multiset<ll> setA;

    for(ll i = 0; i < N; i ++){
        ll a;
        cin >> a;
        setA.insert(a);
        // cout << "i = " << i << endl;
        if(setA.size() >= 3){
            ll cnt = 0;
            for(auto e = setA.rbegin(); e != setA.rend(); e ++){
                cnt ++;
                // cout << "e = " << *e << endl;
                if(cnt == 3){
                    cout << *e << endl;
                    break;
                }
            }
        }

    }

}
