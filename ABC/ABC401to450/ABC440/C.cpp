#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;


void solveCase(){
    ll N, W;
    cin >> N >> W;
    vector<ll> vecC(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecC[i];
    }

    vector<ll> remTotal(2 * W, 0);
    for(ll i = 0; i < N; i ++){
        remTotal[i % (2 * W)] += vecC[i];
    }
    ll min = 0;
    for(ll i = 0; i < W; i ++){
        min += remTotal[i];
    }
    ll left = 0; 
    ll right = W;
    ll nowTotal = min;
    for(ll i = 0; i < 2 * W; i ++){
        nowTotal -= remTotal[left];
        nowTotal += remTotal[right];
        left += 1;
        right += 1;
        left %= 2 * W;
        right %= 2 * W;
        if(nowTotal < min){
            min = nowTotal;
        }

    }
    cout <<  min << endl;
}



int main(){
    ll T;
    cin >> T;
    for(int i = 0; i < T; i ++){
        solveCase();
    }

}