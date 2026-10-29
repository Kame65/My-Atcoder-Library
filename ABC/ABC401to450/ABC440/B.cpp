#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>>vecT(N);
    for(int i = 0; i < N; i ++){
        vecT[i].resize(2);
        vecT[i][0] = i + 1;
        cin >> vecT[i][1];
    }
    sort(vecT.begin(),vecT.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});

    for(int i = 0; i < 3; i ++){
        cout << vecT[i][0] << " ";
    }
    cout << endl;


}