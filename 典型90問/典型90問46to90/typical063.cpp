#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


ll H, W;
vvl vecP;
vl choice;
vl results;

void cntAll(ll idx){
    if(idx < H){
        choice[idx] = false;
        cntAll(idx + 1);
        choice[idx] = true;
        cntAll(idx + 1);
    }else{
        unordered_map<ll, ll> oneMap;
        ll choiceNum = 0;
        ll before = -1;
        bool isOk = true;
        for(ll x = 0; x < W; x ++){
            ll before = -1;
            choiceNum = 0;
            isOk = true;
            for(ll y = 0; y < H; y ++){
                if(choice[y]){
                    choiceNum ++;
                    if(before == -1){
                        before = vecP[y][x];
                    }else{
                        if(vecP[y][x] != before){
                            isOk = false;
                        }
                    }
                }
            }
            if(isOk){
                oneMap[before] ++;
            }
        }
        // cout << "chpoiceNum: ";
        // for(ll i = 0; i < H; i ++){
        //     if(choice[i]){
        //         cout << i << " ";
        //     }
        // } 
        // cout << endl;
        if(oneMap.size() > 0){
            ll max = 0;
            for(auto& [key, value] : oneMap){
                if(max < value){
                    max = value;
                }
            }
            results.push_back(max * choiceNum);
            // cout << "max: " << choiceNum << ", " << max << endl;
        }
    }

}

int main(){
    cin >> H >> W;
    choice = vl(H);
    vecP = vvl(H, vl(W));
    for(ll y = 0; y < H; y ++){
        for(ll x = 0; x < W; x ++){
            cin >> vecP[y][x];
        }
    }
    cntAll(0);

    cout << *max_element(results.begin(), results.end()) << endl;

    // for(ll i:results){
    //     cout << i << " ";
    // }
    // cout << endl;




}