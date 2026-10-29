#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
using ll = long long int;

unordered_map<ll, bool> results, trash;
vector<ll> squares;
vector<vector<ll>>memo;



ll N;
vector<ll>vecA;

int main(){
    ll result = 0;
    map<ll, ll>map7;
    map<ll, ll>map3;
    cin >> N;
    vecA.resize(N + 1);
    for(int i = 0; i < N; i ++){
        cin >> vecA[i];
        ll a = vecA[i];
        if(a % 7 == 0){
            ll q = a / 7;
            if(map7.find(q) != map7.end()){
                map7[q] += 1;
            }else{
                map7[q] = 1;
            }
            
        }
        if(a % 5 == 0){
            
            ll q = a / 5;
            // cout << q << endl;
            // vec5[q] += 1;
            vector<ll>memoVec = {q, map7[q], map3[q]};
            memo.push_back(memoVec);
            // cout << vec7[q] << " " << vec3[q] << endl; 
            if(map3.find(q) != map3.end() && map7.find(q) != map7.end()){
                result += map7[q] * map3[q];
            }
        }
        if(a % 3 == 0){
            ll q = a / 3;
            if(map3.find(q) != map3.end()){
                map3[q] += 1;
            }else{
                map3[q] = 1;
            }
            
        }
    }
    // cout << result << endl;
    for(ll i = 0; i < memo.size(); i ++){
        ll q = memo[i][0];
        if(map3.find(q) != map3.end() && map7.find(q) != map7.end()){
            result += (map7[q] - memo[i][1]) * (map3[q] - memo[i][2]);
        }

    }

    cout << result << endl;


}