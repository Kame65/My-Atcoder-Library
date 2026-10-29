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


ll N, K;
vl memoXtoI, memoItoX;

ll culc(ll x){
    string strY = to_string(x);
    ll y = 0;
    // cout << "y = " << strY << endl;
    for(ll i = 0; i < strY.size(); i ++){
        y += strY[i] - '0';
        
    }
    // cout << y << endl;
    return (x + y) % (ll)1e5;
}

int main(){
    cin >> N >> K;
    ll ans;
    memoXtoI = vl(1e5, -1);
    memoItoX = vl(1e5, -1);
    memoItoX[0] = N;
    memoXtoI[N] = 0;
    
    ll x = N;
    ll startIdx, loopRange;
    for(ll i = 1; i <= K; i ++){
        x = culc(x);
        // cout << x << endl;
        if(memoXtoI[x] < 0){
            memoXtoI[x] = i;
            memoItoX[i] = x;
            ans = x;

        }else{
            startIdx = memoXtoI[x];
            loopRange = i - startIdx;
            ans = memoItoX[(K - startIdx) % loopRange + startIdx];
            break;
        }
        
    }
    cout << ans << endl;

}