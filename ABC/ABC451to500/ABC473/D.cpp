#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <deque>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


set<deque<ll>> res;
ll N, K;
    void search(ll idx, deque<ll> now, ll total){// N桁目から判定
        // cout << "debag idx: " << idx << " str: " << nowStr << " total: " << total << endl;
        if(idx == 1){
            now.push_front(total);
            res.insert(now);
            // cout << "insert: " << nowStr << endl;
            return;
        }
        for(ll i = total / idx; i >= 0; i --){
            deque<ll> one = now;
            one.push_front(i);
            search(idx - 1, one , total - (i * idx));
        }

    }

int main(){
    cin >> N >> K;

    search(N, deque<ll>(), K);

    for(deque s: res){
        for(ll i = 0; i < N; i ++){
            cout << s.front() << " ";
            s.pop_front();
        }
        cout << endl;
    }

    
}
