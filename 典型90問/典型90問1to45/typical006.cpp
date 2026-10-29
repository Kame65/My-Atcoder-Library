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


ll N, K;
vc vecS;
int main(){
    cin >> N >> K;
    vecS = vc(N);
    vvl strIdx(26, vl());
    for(ll i = 0; i < N; i ++){
        cin >> vecS[i];
        // cout << vecS[i] - 'a' << endl;
        strIdx[int(vecS[i] - 'a')].push_back(i);
    }
    string ans = "";
    ll lastIdx = -1;
    for(ll i = 0; i < K; i ++){
        
        for(ll c = 0; c < 26; c ++){
            // cout << ans << endl;
            vl vecC = strIdx[c];
            auto iter = upper_bound(vecC.begin(), vecC.end(), lastIdx);
            if(iter == vecC.end()){
                continue;
            }
            // if(iter != strIdx[c].end()){
            //     cout << *iter << ", " << strIdx[c].end() - iter << endl;
            // }
            // cout << char(c + 'a') << ", size: " << strIdx[c].size() << endl;
            // for(ll j = 0; j < strIdx[c].size(); j ++){
            //     cout << strIdx[c][j] << " ";
            // }
            // cout << endl;
            ll nextIdx = *iter;
            
            if(N - nextIdx > K - i - 1){
                // cout << "nextIdx: " << nextIdx << endl;
                ans += char (c + 'a');
                lastIdx = nextIdx;
                break;
            }
        }
        // cout << i << ", " << ans << endl;
        
    }
    cout << ans << endl;


    
}