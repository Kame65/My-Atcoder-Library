#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>

using namespace std;
using ll = long long int;


ll N, M;
string inputS, inputT;
vector<int> vecS, vecT;
vector<ll> vec;
vector<vector<ll>> vecl;

int main(){
    cin >> N >> M;
    cin >> inputS;
    cin >> inputT;
    vecS.resize(N);
    vecT.resize(M);
    vector<ll> results;
    for(int i = 0; i < N; i ++){
        vecS[i] = (int)inputS[i] - '0';
    }
    for(int i = 0; i < M; i ++){
        vecT[i] = (int)(inputT[i] - '0');
    }
    for(int i = 0; i < N - M + 1; i ++){
        int result = 0;
        for(int j = 0; j < M; j ++){
            // vecS[j]とvecT[j]の比較
            // cout << i << " " << j << " " << vecS[j] << vecT[j] << endl;
            if(vecS[i + j] >= vecT[j]){
                result += vecS[i + j] - vecT[j];
            }else{
                result += 10 + vecS[i + j] - vecT[j];
            }
            // cout << result << endl;
        }
        // cout <<i << " " << result << endl;
        results.push_back(result);

    }
    ll min = results[0];
    for(int i = 0; i < results.size(); i ++){
        // cout << i << ": " << results[i] << endl;
        if(min > results[i]){
            // cout << results[i] << endl;
            min = results[i];
        }
    }
    cout << min << endl;
    
}