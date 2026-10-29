#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, L, R;
    string S;
    cin >> N >> L >> R;
    cin >> S;
    vvl memo(N + 1);
    for(ll i = 0; i < N; i ++){
        memo[0].resize(26, 0);
    }
    for(ll i = 1; i <= N; i ++){    
        memo[i] = memo[i - 1]; 
        char c = S[i - 1];
        memo[i][c - 'a'] += 1;
    }
    ll total = 0;
    for(ll i = 0; i < N; i ++){
        ll num = S[i] - 'a';
        if(i + 1 + L > N){
            break;
        }
        ll min = memo[i + L][num];
        ll max;
        if(i + 1 + R > N){
            max = memo[N][num];
        }else{
            max = memo[i + 1 + R][num];
        }
        ll jNum = max - min;
        // cout << "num = " << num <<  ", " << i << ", " << max << ", " << min << endl;
        if(jNum >= 1){

            total += jNum;
        }
        
    }
    cout << total << endl;
}
