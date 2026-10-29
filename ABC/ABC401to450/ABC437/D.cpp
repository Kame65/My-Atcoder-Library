#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
using ll = long long int;


ll N, M, result;
ll mod = 998244353;
vector<ll> vecA, vecB, cumSumB;

int main(){
    cin >> N >> M;
    vecA.resize(N);
    vecB.resize(M);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < M; i ++){
        cin >> vecB[i];
    }
    // cout << "input finish" << endl;
    //input is OK
    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());
    
    cumSumB.push_back(0);
    cumSumB.push_back(vecB[0]);
    for(ll i = 1; i < M; i ++){
        cumSumB.push_back(cumSumB[i] + vecB[i]);
    }
    result = 0;
    for(int i = 0; i < N; i ++){
        ll a = vecA[i];
        ll l = -1;
        ll r = M;
        while(r - l > 1){
            // cout << "l, r = " << l << " " << r << endl;
            ll mid = (l + r) / 2;
            if(vecB[mid] >= a){
                r = mid;
            }else{
                l = mid;
            }
        }
        // r = 最小のvecB[r] >= a
        //0~rでa > r
        // cout << "idx = " << r << endl;
        result += (a * r - cumSumB[r]) % mod;
        // cout << "result = " << result << endl;
        // cout << cumSumB[0] << " " << cumSumB[1] << " " << cumSumB[2] << endl;
        // cout << cumSumB[M] - cumSumB[r] << endl;
        result += (cumSumB[M] - cumSumB[r] - a * (M - r)) % mod; 
        result %= mod;
        // cout << "result = " << result << endl; 

    }
    cout << result << endl;
}