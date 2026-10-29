#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
using ll = long long int;

ll N, M, Q, queN, queV;
vector<ll> listX, listY;
vector<vector<ll>> canBack;
vector<bool> canGoB;

void changeColor(ll v){
    if(canGoB[v]){
        return;
    }else{
        canGoB[v] = true;
        for(size_t i = 0; i < canBack[v].size(); i ++){
            changeColor(canBack[v][i]);
        }
    }
}


void solveQ(ll qNum, ll qV){

    if(qNum == 1){
        changeColor(qV);
    }else{
        if(canGoB[qV]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    } 
}

int main(){
    cin >> N >> M;
    listX.resize(M);
    listY.resize(M);
    for(ll i = 0; i < M; i ++){
        cin >> listX[i] >> listY[i];
    }
    canBack.resize(N + 1);//iにi番の頂点
    for(ll i = 0; i < M; i ++){
        canBack[listY[i]].push_back(listX[i]);
    }
    cin >> Q;
    // cout << Q << endl;
    canGoB.resize(N + 1, false);
    // cout << "Why" << endl;
    for(ll i = 0; i < Q; i ++){
        cin >> queN >> queV;
        // cout << "OK";
        solveQ(queN, queV);
    }
}