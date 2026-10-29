#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll before = 0;
    ll ans = 0;
    for(ll i = 0; i < N; i ++){
        if(S[i] == 'R') before ++;
        else before = 0;
        if(ans < before){
            ans = before;
        }
    }
    cout << ans << endl;
}