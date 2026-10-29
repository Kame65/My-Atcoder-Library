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
    ll N, M;
    cin >> N >> M;
    vvl vecADB(N, vl(3));
    vl color(N + 1, 0);
    for(ll i = 0; i < N; i ++){
        cin >> vecADB[i][0] >> vecADB[i][1] >> vecADB[i][2];
        color[vecADB[i][0]] ++;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i ++){
        if(color[i] > 0){
            ans ++;
        }
    }
    
    sort(vecADB.begin(),vecADB.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});
    // Dの順にsort


    ll idx = 0;
    for(ll i = 1; i <= M; i ++){
        if(idx < N){
            while(vecADB[idx][1] == i){
                color[vecADB[idx][0]] --;
                if(color[vecADB[idx][0]] == 0){
                    ans --;
                }
                if(color[vecADB[idx][2]] == 0){
                    ans ++;
                }
                color[vecADB[idx][2]] ++;
                idx ++;
                if(idx == N){
                    break;
                }

            }
        }
        
        cout << ans << endl;
    }


    
}