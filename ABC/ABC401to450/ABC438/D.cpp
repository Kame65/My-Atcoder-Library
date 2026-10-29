#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using ll = long long int;


ll N;
vector<ll> vecA, vecB, vecC;
vector<vector<ll>> vecl;
vector<ll> maxB;

int main(){
    cin >> N;
    vecA.resize(N);
    vecB.resize(N);
    vecC.resize(N);

    for(ll j = 0; j < N; j ++){
        cin >> vecA[j];
    }
    for(ll i = 0; i < N; i ++){
        cin >> vecB[i];
    }
        for(ll i = 0; i < N; i ++){
        cin >> vecC[i];
    }

        vector<ll> sumA(N), sumB(N), sumC(N);
    sumA[0] = vecA[0];
    sumB[0] = vecB[0];
    sumC[0] = vecC[0];
    for(ll i = 1; i < N; i ++){
        sumA[i] = sumA[i - 1] + vecA[i];
        sumB[i] = sumB[i - 1] + vecB[i];
        sumC[i] = sumC[i - 1] + vecC[i];
    }

    vector<vector<ll>>vecBmerit(N - 1);
    for(ll i = 0; i < N - 1; i ++){
        vecBmerit[i].resize(2);
        vecBmerit[i][0] = i;
        vecBmerit[i][1] = sumB[i] - sumC[i];
    }

    // for(int i = 0; i < vecBmerit.size(); i ++){
    //     cout << vecBmerit[i][1] << " ";
    // }
    // cout <<endl;


    sort(vecBmerit.begin(),vecBmerit.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});
    maxB.resize(N, -1);
    for(ll i = 0; i < N - 1; i ++){
        // ll max = vecBmerit[i][1];
        ll idx = vecBmerit[N - i - 2][0];
        ll j= idx;

        // cout << "j = " << j << endl;
        while(true){

            if(maxB[j] > 0 || j < 0){
                break;
            }
            maxB[j] = idx;
            j --;
        }
    }
    // for(int i = 0; i < maxB.size(); i ++){
    //     cout << maxB[i] << " ";
    // }  
    // cout <<endl;



    vector<ll>results;
    for(ll x = 0; x < N - 2; x ++){
        ll idx = maxB[x + 1];
        // cout << x << " " << idx << endl;
        // cout << x << "= " << sumA[x] << endl;
        // cout << idx << "= " << sumB[idx] - sumB[x] << endl;
        // cout << "N - 1 = " <<sumC[N - 1] - sumC[idx] << endl;

        ll result = sumA[x] + sumB[idx] - sumB[x] + sumC[N - 1] - sumC[idx];
        results.push_back(result);
    }
    ll max = results[0];
    for(ll i = 0; i < results.size(); i ++){
        // cout << "result = " <<  results[i] << endl;
        if(max < results[i]){
            max = results[i];
        }
    }
    cout << max << endl;

}