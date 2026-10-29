#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;

vl vecA, vecB;
vl dp0, dp1;
ll getDp1(ll);
ll getDp0(ll);

ll getDp0(ll n){
    if(dp0[n] > 0){
        return dp0[n];
    }
    if(n == 0){
        if(vecA[0] == 1){
            dp0[0] = 1;
            return 1;
        }else{
            dp0[0] = 0;
            return 0;
        }
    }
    ll way;
    if(vecA[n] % 2 == vecB[n - 1]){//両方変えないor両方+1
        if(vecA[n] % 2 == 1){
            way = getDp1(n - 1) + 1;
        }else{
            way = getDp0(n - 1);//1つ前は0
        }
    }else{
        if(vecA[n] % 2 == 1){
            way = getDp0(n - 1) + 1;
        }else{
            way = getDp1(n - 1);
        }
    }
    return way;
}
ll getDp1(ll n){
    if(dp1[n] > 0){
        return dp1[n];
    }
    if(n == 0){
        if(vecA[0] == 1){
            dp1[0] = 0;
            return 0;
        }else{
            dp1[0] = 1;
            return 1;
        }
    }
    ll way;
    if(vecA[n] % 2 == vecB[n - 1]){//両方変えないor両方+1
        if(vecA[n] % 2 == 1){
            way = getDp0(n - 1);
        }else{
            way = getDp1(n - 1) + 1;
        }
    }else{
        if(vecA[n] % 2 == 1){
            way = getDp1(n - 1);
        }else{
            way = getDp0(n - 1) + 1;
        }
    }
    return way;

}

int main(){
    ll N, M;
    cin >> N >> M;
    vecA = vl(N);
    vecB = vl(N - 1);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N - 1; i ++){
        cin >> vecB[i];
    }

    dp0 = vl(N, - 1);
    dp1 = vl(N, -1);


    cout << min(getDp0(N - 1), getDp1(N - 1)) << endl;
}