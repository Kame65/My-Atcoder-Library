#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


ll N, M;


int main(){
    cin >> N >> M;
    set<string> setS;
    vector<string> vecS;

    for(ll i = 0; i < N; i ++){
        string s;
        cin >> s;
        setS.insert(s);
    }
    for(string s:setS){
        vecS.push_back(s);
    }
    vector<bool> check(N, false);
    ll idx = 0;
    string ans = "";
    ll checKcnt = 0;
    while(checKcnt < N){

        if(idx == M){
            cout << "No" << endl;
            return 0;
        }
        ll cnt0 = 0, cnt1 = 0;
        for(ll i = 0; i < N; i ++){
            if(check[i]){
                continue;;
            }
            if(vecS[i][idx] == '0'){
                cnt0 ++;
            }else{
                cnt1 ++;
            }

        }
        if(cnt0 > cnt1){
            for(ll i = 0; i < N; i ++){
                if(check[i]){
                    continue;;
                }
                if(vecS[i][idx] == '0'){
                    check[i] = true;
                    checKcnt ++;
                }

            }
            ans += "0";
        }else{
            for(ll i = 0; i < N; i ++){
                if(check[i]){
                    continue;;
                }
                if(vecS[i][idx] == '1'){
                    check[i] = true;
                    checKcnt ++;
                }
            }
            ans += "1";
        }
        idx ++;
        // cout << ans << endl;

    }
    cout << "Yes" << endl;
    cout << ans;
    for(ll i = 0; i < M - ans.size(); i ++){
        cout << "0";
    }
    cout << endl;



}