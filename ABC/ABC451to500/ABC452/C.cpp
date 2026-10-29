#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



ll N, M;
vvl vecAB;
vector<string> vecS;
vector<unordered_map<char, bool>> canPut;

int main(){
    cin >> N;
    vecAB.resize(N);
    for(ll i = 0; i < N; i ++){
        vecAB[i].resize(2);
        cin >> vecAB[i][0] >> vecAB[i][1];
    }
    cin >> M;
    vecS.resize(M);
    for(ll i = 0; i < M; i ++){
        cin >> vecS[i];
    }
    canPut.resize(N);
    for(int i = 0; i < M; i ++){
        for(int j = 0; j < N; j ++){
            int a = vecAB[j][0];
            int b = vecAB[j][1];

            if(vecS[i].size() == a){
                canPut[j][vecS[i][b - 1]] = true;
            }
        }
    }
    for(int i = 0; i < M; i ++){
        bool result = true;
        if(vecS[i].size() == N){
            // cout << "Size OK" << endl;
            for(ll j = 0; j < N; j ++){
                if(!canPut[j][vecS[i][j]]){
                    // cout << vecS[i][j] << endl;
                    result = false;
                }
            }
        }else{
            result = false;
        }
        if(result){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

}