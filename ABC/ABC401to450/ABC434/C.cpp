#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

bool solveCase(ll N, ll H){
    ll nowTi, li, ui, beforeLeft, beforeRight, beforeTi, ti;
    beforeLeft = H;
    beforeRight = H;
    beforeTi = 0;
    
    bool result = true;
    for(int i = 0; i < N; i ++){
        cin >> nowTi >> li >> ui;
        ti = nowTi - beforeTi;
        if(beforeLeft - ti > ui || beforeRight + ti < li){
            result = false;
        }
        beforeLeft = max(beforeLeft - ti, li);
        beforeRight = min(beforeRight + ti, ui);
        beforeTi = nowTi;
    }
    return result;
}

int main(){
    ll T, N, H;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        cin >> N >> H;
        if(solveCase(N, H)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}