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

ll N, K, M;
vvl vecCV;

int main(){

    cin >> N >> K >> M;
    vecCV = vvl(N + 1, vl(2));
    for(ll i = 0; i < N; i ++){
        cin >> vecCV[i][0] >> vecCV[i][1];
    }
    sort(vecCV.begin(),vecCV.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] > beta[1];});
    unordered_map<ll, bool> check;
    ll cnt = 0;
    ll kinds = 0;
    ll ans = 0;
    for(ll i = 0; i < N; i ++){
        // cout << "what" << endl;
        // cout << vecCV[i][0] << vecCV[i][1] << endl;
        if(M - kinds >= K - cnt){
            // cout << "in kind small" << endl;
            if(!check[vecCV[i][0]]){
                check[vecCV[i][0]] = true;
                ans += vecCV[i][1];
                cnt ++;
                kinds ++;

            }
        }else{
            if(!check[vecCV[i][0]]){
                check[vecCV[i][0]] = true;
                kinds ++;
            }
            ans += vecCV[i][1];
            cnt ++;
        }
        
        // cout << "ans" << ans << " " << kinds << endl;

        if(cnt == K){
            break;
        }
    }
    cout << ans << endl;


}