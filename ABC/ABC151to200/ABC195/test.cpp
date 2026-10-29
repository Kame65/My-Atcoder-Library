#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll A, B, W;

bool ok(ll A, ll B, ll N, ll W) {
    return (A * N <= W && W <= B * N);
}

pair<ll,ll> brute(ll A, ll B, ll W) {
    ll mn = 1e18, mx = -1;
    for(ll n=1; n<=1000000; n++){
        if(ok(A,B,n,W)){
            mn = min(mn,n);
            mx = max(mx,n);
        }
    }
    if(mx==-1) return {-1,-1};
    return {mn,mx};
}

pair<ll,ll> your(ll A, ll B, ll W) {
    ll maxLastWeight = W % A;
    ll maxCount = W / A;
    while(true){
        ll n = maxLastWeight / A;
        if(A * n <= maxLastWeight && maxLastWeight <= B * n){
            maxCount += n;
            break;
        }
        maxCount--;
        maxLastWeight += A;
        if(maxCount < 0) break;
    }

    ll minLastWeight = W % B;
    ll minCount = W / B;
    if(A == 1 && minLastWeight != 0){
        minCount += 1;
    }else{
        while(1){
            if(A == 1){

            }
            ll n = minLastWeight / A;
            if(A * n <= minLastWeight && minLastWeight <= B * n){
                minCount += n;
                break;
            }
            minCount -= 1;
            minLastWeight += B;
            if(minCount < 0){
                break;
            }
        }
    }  

    if(minCount < 0) return {-1,-1};
    return {minCount,maxCount};
}

int main(){
    // 全探索：A,B ≤ 1000, W ≤ 1000（十分）
    for(ll A=1;A<=1000;A++){
        for(ll B=A;B<=1000;B++){
            for(ll W=1;W<=5000;W++){
                auto b = brute(A,B,W);
                auto y = your(A,B,W);
                if(b != y){
                    cout << "WA found!\n";
                    cout << "A="<<A<<" B="<<B<<" W="<<W<<"\n";
                    cout << "correct: "<<b.first<<" "<<b.second<<"\n";
                    cout << "yours:   "<<y.first<<" "<<y.second<<"\n";
                    return 0;
                }
            }
        }
    }
    cout << "No WA found.\n";
}
