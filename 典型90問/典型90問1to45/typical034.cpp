#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;


int main(){
    ll N, K;
    cin >> N >> K;
    vl vecA(N);
    unordered_map<ll, ll> memo;
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    ll l = 0, r = 0;
    ll kinds = 0;
    ll max = 0;
    while(r <= N){
        if(kinds <= K){
            if(max < r - l){
                // cout << l << " " << r << endl;
                max = r - l ;
            }
            if(r == N){
                break;
            }
            if(memo[vecA[r]] == 0){//l以上r未満でできているか
                kinds ++;
            }
            memo[vecA[r]] ++;
            r ++;

        }else{

            memo[vecA[l]] --;
            if(memo[vecA[l]] == 0){
                kinds --;
            }
            l ++;
        }
    }
    cout << max << endl;

}