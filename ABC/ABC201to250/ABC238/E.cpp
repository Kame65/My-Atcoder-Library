#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

ll N, Q;
vvl vecF, vecB;
vector<bool> judged;
vl result, imosMemo;



bool judge(ll n){

    if(n == N + 1){
        return true;
    }
    if(judged[n]){
        return false;
    }
    judged[n] = true;
    // 進む場合
    for(ll i = 0; i < vecF[n].size(); i ++){
        if(judge(vecF[n][i] + 1)){
            return true;
        }
    }
    for(ll i = 0; i < vecB[n - 1].size(); i ++){
        if(judge(vecB[n - 1][i])){
            return true;
        }
    }

    return false;
}

int main(){
    cin >> N >> Q;

    vecF = vvl(N + 1);
    vecB = vvl(N + 1);
    result = vl(N + 2, 0);
    judged = vector<bool>(N + 1, false);

    for(ll i = 0; i < Q; i ++){
        ll l, r;
        cin >> l >> r;
        vecF[l].push_back(r);
        vecB[r].push_back(l);

    }
    
    if(judge(1)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}