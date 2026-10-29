#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long int;


ll N, M, C;
vector<ll> keys;
vector<ll> vecA, distanceN;//n人になる距離
map<ll, ll> distanceToNum;//距離からそこまでの人数

int main(){
    cin >> N >> M >> C;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }

    //0から2週分n人になる距離をdistanceNに保持
    distanceN.resize(2 * N + 1);
    sort(vecA.begin(), vecA.end());
    distanceN[0] = 0;
    for(ll i = 0; i < 2 * N; i ++){
        distanceN[i + 1] = vecA[i % N];
        if(i >= N){
            distanceN[i + 1] += M;
        } 
    }
    // cout << "finish input" << endl;
    ll before = 0;//n人め
    for(ll i = 1; i < distanceN.size(); i ++){
        if(distanceN[i] != distanceN[before]){
            // cout << before << " " << i << " " << distanceN[before] << endl;
            distanceToNum[distanceN[before]] = before;
            keys.push_back(distanceN[before]);
        }
        if(i == distanceN.size() - 1){
            distanceToNum[distanceN[i]] = i;
            keys.push_back(distanceN[i]);
        }
        before = i;
    }

    //累積和的なやつ完了
    ll result = 0;

    ll i = 0;
    ll start = 0;
    for(ll i = 0; i <= keys.size(); i ++){
        if(start >= M){
            break;
        }
        ll num = C + distanceToNum[start];//必要人数
        ll distance = distanceN[num];
        ll startWidth;
        if(i == keys.size() - 1){
            startWidth = M - keys[i]; 
        }else{
            if(keys[i + 1] >= M){
                startWidth = M - keys[i];
            }else{
                startWidth = keys[i + 1] - keys[i];
            }
            
        }
        // cout << "start = " << start << endl;
        // cout << "startWidth " << startWidth  << ", num: " << distanceToNum[distance] - distanceToNum[start] << endl;
        
        result += (distanceToNum[distance] - distanceToNum[start]) * startWidth;
        // cout << "result = " << result << endl;
        start += startWidth;
    }

    cout << result << endl;

}