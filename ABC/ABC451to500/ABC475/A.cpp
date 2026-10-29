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
    string S;
    cin >> S;
    string ans;
    for(ll i = 0; i < S.size(); i ++){
        if(i != 0){
            ans.push_back('o');
        }
        ans.push_back(S[i]);
    }
    cout << ans << endl;
}
