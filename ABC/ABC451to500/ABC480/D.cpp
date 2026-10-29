#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll N, Q; cin >> N >> Q;
    vl vecA(N + 1, 0);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }
    vl sumA(N + 1, 0);

    for(ll i = 1; i <= N; i ++){
        sumA[i] = sumA[i - 1] + vecA[i];
        // cout << sumA[i] << endl;
    }
    vl sumsumA(N + 1, 0);
    for(ll i = 1; i <= N; i ++){
        sumsumA[i] = sumsumA[i - 1] + sumA[i];
        // cout << sumsumA[i] << endl;
    }
    vl sigK(N, 0);
    ll total = 0;
    for(ll i = 1; i < N; i ++){
        total += i;
        sigK[i] = total;
    }

    for(ll q = 0; q < Q; q ++){
        ll l, r;
        cin >> l >> r;
        ll suml = 0, sumr = 0;
        ll lsumsum = upper_bound(sigK.begin(), sigK.end(), l - 1) - sigK.begin() - 1;
        ll rsumsum = upper_bound(sigK.begin(), sigK.end(), r) - sigK.begin() - 1;
        // cout << "idx \n";
        // cout << lsumsum << endl;
        // cout << rsumsum << endl;
        suml += sumsumA[lsumsum];
        sumr += sumsumA[rsumsum];
        // cout << suml << endl;
        
        // cout << "before sum" << endl;
        // cout << sumr << endl;
        // cout << suml << endl;
        
        suml += sumA[l - 1 - sigK[lsumsum]];
        sumr += sumA[r - sigK[rsumsum]];
        // cout << "sum" << endl;
        // cout << sumr << endl;
        // cout << suml << endl;

        cout << sumr - suml << endl;
    }
}