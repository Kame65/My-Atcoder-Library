#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long int;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> vecC(M + 1);
    for(int i = 1; i < M + 1; i ++){
        cin >> vecC[i];
    }
    ll result = 0;
    for(ll i = 0; i < N; i ++){
        ll a, b;
        cin >> a >> b;
        if(b < vecC[a]){
            result += b;
            vecC[a] -= b;
        }else{
            result += vecC[a];
            vecC[a] = 0;
        }
        // cout << i << ", " << result << endl;
    }
    cout << result << endl;
}