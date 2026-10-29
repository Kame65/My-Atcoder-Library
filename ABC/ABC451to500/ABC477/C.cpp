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


vvl dp;
string S, T;

ll search(ll nT, ll nS){//Tのn文字目, Sのn文字目 (idx)
    if(dp[nT][nS] != -2){
        // cout << "already: " << nT << " " << nS << " " << dp[nT][nS] << endl;
        return dp[nT][nS];
        
    }
    // cout << nT << ", " << nS << endl;
    if(nT == 0){
        // cout << "t = 0: " << S[nS] << " " << T[nT] << endl;
        if(S[nS] == T[0]){
            dp[nT][nS] = nS;
            return nS;
        }else{
            if(nS == 0){
                dp[nT][nS] = -1;
                return -1;
            }
            dp[nT][nS] = search(nT, nS - 1);
            return dp[nT][nS];
        }
    }else{
        if(nS == 0){
            dp[nT][nS] = -1;
            return -1;
        }
        // cout << "in else" << endl;
        if(S[nS] == T[nT]){
            // cout << "OK" << endl;
            dp[nT][nS] = max(search(nT - 1, nS - 1), search(nT, nS - 1));
            return dp[nT][nS];
        }else{
            // cout << "else2" << endl;
            dp[nT][nS] = search(nT, nS - 1);
            return dp[nT][nS];
        }

    }
}

int main(){
    ll Q;

    cin >> Q >> S >> T;
    vl vecL(Q), vecR(Q);
    for(ll i = 0; i < Q; i ++){
        cin >> vecL[i] >> vecR[i];
    }
    dp = vvl(T.size(), vl(S.size(), -2));

    vl result(S.size() + 1);

    for(ll i = 0; i < S.size(); i ++){
        // cout << "search: " << T.size() - 1 << " " << i << endl;
        result[i + 1] = search(T.size() - 1, i) + 1;
        // cout << result[i + 1] << endl;
    }
    // for(ll i = 0; i < S.size(); i ++){
    //     // result[i + 1] = search(T.size() - 1, i);
    //     cout << result[i + 1] << " ";
    // }
    // cout << endl;

    for(ll t = 0; t < T.size(); t ++){
        for(ll s = 0; s < S.size(); s ++){
            cout << dp[t][s] << " ";
        }
        cout << endl;
    }
    for(ll i = 0; i < Q; i ++){
        if(result[vecR[i]] >= vecL[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    

}
