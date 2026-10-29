#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

ll N;
vector<ll> listU, listD, listL, listR;
vector<vector<ll>> imosSky, sky, sumOneSky;

int main(){
    cin >> N;
    listU.resize(N);
    listD.resize(N);
    listL.resize(N);
    listR.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> listU[i] >> listD[i] >> listL[i] >> listR[i];
    }
    imosSky.resize(2002);
    sky.resize(2002);
    sumOneSky.resize(2002);
    for(int i = 0; i < 2002; i ++){
        imosSky[i].resize(2002, 0);
        sky[i].resize(2001, 0);
        sumOneSky[i].resize(2001, 0);
    }
    for(ll i = 0; i < N; i ++){
        imosSky[listU[i]][listL[i]] += 1;
        imosSky[listU[i]][listR[i] + 1] -= 1;
        imosSky[listD[i] + 1][listL[i]] -= 1;
        imosSky[listD[i] + 1][listR[i] + 1] += 1;
    }
    for(ll y = 1; y <= 2000; y ++){
        for(ll x = 1; x <= 2000; x ++){
            sky[y][x] = sky[y][x - 1] + imosSky[y][x];
        }
    }
    for(ll y = 1; y <= 2000; y ++){
        for(ll x = 1; x <= 2000; x ++){
            sky[y][x] += sky[y - 1][x];
        }
    }
    //imos完了

    int countZero = 0;
    for(ll y = 1; y <= 2000; y ++){
        for(ll x = 1; x <= 2000; x ++){
            sumOneSky[y][x] = sumOneSky[y - 1][x] + sumOneSky[y][x - 1] - sumOneSky[y - 1][x - 1];
            if(sky[y][x] == 1){
                sumOneSky[y][x] += 1;
            }
            if(sky[y][x] == 0){
                countZero += 1;
            }
        }
    }
    for(ll i = 0; i < N; i ++){
        cout << countZero + sumOneSky[listD[i]][listR[i]] 
        - sumOneSky[listU[i] - 1][listR[i]] - sumOneSky[listD[i]][listL[i] - 1] 
        + sumOneSky[listU[i] - 1][listL[i] - 1] << endl;
    }
    
}