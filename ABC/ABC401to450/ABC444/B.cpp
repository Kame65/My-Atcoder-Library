#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

ll N, K;

bool judge(ll n){
    string s = to_string(n);
    ll total = 0;
    for(ll i = 0; i < s.size(); i ++){
        int num = s[i] - '0';
        total += num;
    }
    // cout << n << ", " << total << endl;
    if(total == K){
        return true;
    }
    return false;
}

int main(){
    cin >> N >> K;
    ll ans = 0;
    for(ll i = 1; i <= N; i ++){
        if(judge(i)){
            ans ++;
        }
    }
    cout << ans << endl;
}