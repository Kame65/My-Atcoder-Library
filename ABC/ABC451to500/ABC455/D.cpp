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


ll N, Q;
vl vecFirst;

int main(){
    cin >> N >> Q;
    vvl vPair(N + 1);//pairは下と上のトランプ
    
    vecFirst = vl(N + 1);
    for(ll i = 1; i <= N; i ++){
        vecFirst[i] = i;
        vPair[i] = {0, 0}; 
    }
    for(ll i = 0; i < Q; i ++){
        ll C, Q;
        cin >> C >> Q;
        if(vPair[C][0] == 0){
            vecFirst[C] = 0;
        }else{
            vPair[vPair[C][0]][1] = 0;
        }
        vPair[C][0] = Q;
        vPair[Q][1] = C;
    }
    for(ll i = 1; i <= N; i ++){
        ll one = vecFirst[i];
        if(one == 0){
            cout << 0 << " ";
        }else{
            ll res = 0;
            while(true){
                res ++;
                if(vPair[one][1] != 0){
                    one = vPair[one][1];
                }else{
                    break;
                }
            }
            cout << res << " ";
        }
        
    }
    cout << endl;

}