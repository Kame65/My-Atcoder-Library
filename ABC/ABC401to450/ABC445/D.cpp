#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;




int main(){
    ll H, W, N;
    cin >> H >> W >> N;
    vvl vecHW(N);
    for(ll i = 0; i < N; i ++){
        vecHW[i].resize(3);
        vecHW[i][0] = i;
        cin >> vecHW[i][1] >> vecHW[i][2];
    }
    vvl vecH = vecHW;
    vvl vecW = vecHW;
    vvl result = vecHW;
    vector<bool> trash(N, false);
    sort(vecH.begin(),vecH.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});
    sort(vecW.begin(),vecW.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[2] < beta[2];});
    
    while(true){
        // cout << H << ", " << W  << endl;

        if(vecH.size() != 0 && vecH.back()[1] >= H){
            
            ll idx = vecH.back()[0];
            ll h = vecH.back()[1];
            ll w = vecH.back()[2];
            if(trash[idx]){
                vecH.pop_back();

            }else{
                result[idx][1] = 1;
                result[idx][2] = W - w + 1;
                W -= w;
                vecH.pop_back();
                trash[idx] = true;
                // cout << idx << ", h=" << h << ", w=" << w << endl;
                // cout << H << ", " << W  << endl;
            }

        }
        if(vecW.size() != 0 && vecW.back()[2] >= W){
            
            ll idx = vecW.back()[0];
            ll h = vecW.back()[1];
            ll w = vecW.back()[2];
            if(trash[idx]){
                vecW.pop_back();

            }else{
                result[idx][1] = H - h + 1;
                result[idx][2] = 1;
                H -= h;
                vecW.pop_back();
                trash[idx] = true;
                // cout << idx << ", h=" << h << ", w=" << w << endl;

                // cout << H << ", " << W  << endl;
            }

        }
        if(H == 0 || W == 0){
            break;
        }
    }
    for(ll i = 0; i < N; i ++){
        cout << result[i][1] << " " << result[i][2] << endl;
    }
}

