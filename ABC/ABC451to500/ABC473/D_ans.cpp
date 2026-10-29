#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <set>
#include <string>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


set<string> res;
ll N, K;
    void search(ll idx, string nowStr, ll total){// N桁目から判定
        // cout << "debag idx: " << idx << " str: " << nowStr << " total: " << total << endl;
        if(total < 0){
            return;
        }
        if(idx == 1){
            nowStr = to_string(total) + " " + nowStr;
            res.insert(nowStr);
            // cout << "insert: " << nowStr << endl;
            return;
        }
        for(ll i = total / idx; i >= 0; i --){
            // cout << i << endl;
            search(idx - 1, to_string(i) + " " + nowStr, total - (i * idx));
        }

    }

int main(){
    cin >> N >> K;

    search(N, "", K);

    for(string s: res){
        cout << s << endl;
    }

    
}
