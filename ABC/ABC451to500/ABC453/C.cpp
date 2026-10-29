#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long int;
using vl = vector<ll>;

ll N;
vl vecL, results;

void getValues(ll cnt, ll loc, ll idx){
    // cout << cnt << ", " << loc << ", " << idx << endl;
    if(idx >= N){
        results.push_back(cnt);
        return;
    }
    int plus = -1;
    if(loc >= 0){
        plus = 1;
    }
    ll nextLoc;
    ll nextCnt;
    int nextPlus;
    nextLoc = loc + vecL[idx];
    nextPlus = -1;
    nextCnt = cnt;
    if(nextLoc >= 0){
        nextPlus = 1;
    }
    if(plus * nextPlus < 0){
        nextCnt = cnt + 1; 
    }
    getValues(nextCnt, nextLoc, idx + 1);
    nextLoc = loc - vecL[idx];
    nextPlus = -1;
    nextCnt = cnt;
    if(nextLoc >= 0){
        nextPlus = 1;
    }
    if(plus * nextPlus < 0){
        nextCnt = cnt + 1; 
    }
    getValues(nextCnt, nextLoc, idx + 1);


}

int main(){
    cin >> N;
    vecL.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecL[i];
    }

    getValues(0, 0, 0);

    auto max = max_element(results.begin(), results.end());
    cout << *max << endl;
}