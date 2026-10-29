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
vl vecA;

vl cum;

ll search(ll start, ll times, ll minIdx, ll ans){
    if(start == N + 1){
        return ans;
    }
    ll left = start - 1;
    ll right = start;
    // cout << "s: " << start << "times: " << times << "minIdx: " << minIdx << "ans " << ans << endl;
    while(right <= minIdx && cum[right] - cum[left] != K * times){
        // cout << right << endl;
        if(cum[right] - cum[left] > K * times){
            left ++;
        }else{
            right ++;
        }
    }
    if(cum[right] - cum[left] == K * times){
        minIdx = right;
        if(cum[right] - cum[start - 1] < K * (times + 1)){
            return search(right + 1, 1, N, ans + 1);
        }else{
            return search(start, times + 1, minIdx, ans + 1);
        }
    }else{
        if(cum[minIdx] - cum[start - 1] < K * (times + 1)){
            if(minIdx == N){
                return ans;
            }else{
                return search(minIdx + 1, 1, N, ans);
            }
            
        }else{
            return search(start, times + 1, minIdx, ans);
        }

    }


}


int main(){
    cin >> N >> K;
    vecA = vl(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    cum = vl(N + 1, 0);
    for(ll i = 1; i <= N; i ++){
        cum[i] = vecA[i - 1] + cum[i - 1];
    }

    cout << search(1, 1, N, 0) << endl;;



    
}
