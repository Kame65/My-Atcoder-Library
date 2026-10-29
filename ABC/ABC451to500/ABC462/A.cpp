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
    string s;
    cin >> s;
    string ans;

    for(ll i = 0; i < s.size(); i ++){
        if('0' <= s[i] && s[i] <= '9'){
            ans += s[i];
        }
    }
    cout << ans << endl;
}