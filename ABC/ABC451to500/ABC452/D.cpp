#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


unordered_map<char, vl> charToIdx;
vl results; 
string S, T;


int main(){
    cin >> S >> T;
    int sizeT = T.size();
    int sizeS = S.size();
    for(ll i = 0; i < sizeS; i ++){
        charToIdx[S[i]].push_back(i);
    }
    results.resize(sizeS, -1);
    for(ll i = 0; i < sizeS; i ++){
        int idx = i - 1;
        for(int j = 0; j < sizeT; j ++){
            auto iterI = lower_bound(charToIdx[T[j]].begin(), charToIdx[T[j]].end(), idx + 1);
            if(iterI == charToIdx[T[j]].end()){
                results[i] = sizeS;
                break;
            }
            idx = *iterI;
            
        }
        if(results[i] < 0){
            results[i] = idx;
        }

    }
    ll result = 0;
    for(ll i = 0; i < results.size(); i ++){
        result += results[i] - i;
    }
    cout << result << endl;
}