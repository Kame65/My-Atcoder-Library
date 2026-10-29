#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;




ll N;
string T;
vector<string> vecS;
vl firstNums, lastNums;




int main(){
    cin >> N >> T;
    vecS = vector<string>(N);
    firstNums = vl(N);
    lastNums = vl(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecS[i];
        ll firstNum = 0;
        for(ll j = 0; j < vecS[i].size(); j ++){
            if(firstNum == T.size()){
                break;
            }
            if(T[firstNum] == vecS[i][j]){
                firstNum ++;
            }
        }
        firstNums[i] = firstNum;

        ll lastNum = 0;
        for(ll j = 0; j < vecS[i].size(); j ++){
            if(lastNum == T.size()){
                break;
            }
            if(T[T.size() - 1 - lastNum] == vecS[i][vecS[i].size() - 1 - j]){
                lastNum ++;
            }
        }
        lastNums[i] = lastNum;
    }

    ll ans = 0;
    sort(lastNums.begin(), lastNums.end());
    for(ll i = 0; i < N; i ++){
        auto iterA = lower_bound(lastNums.begin(), lastNums.end(), T.size() - firstNums[i]);
        ans += lastNums.end() - iterA;
    }
    cout << ans << endl;

}