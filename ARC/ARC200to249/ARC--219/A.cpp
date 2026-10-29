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
string solve(ll idx, vector<string>& veS){
    // cout << idx << endl;
    // for(string s:veS){
    //     cout << s << " ";
    // }
    // cout << endl;

    ll mid = -1;
    if(veS.size() == 0){
        return "";
    }
    if(idx == M){
        return "x";
    }
    for(ll i = 0; i < veS.size(); i ++){
        // cout << i << ", " << idx << "?" << veS[i][idx] << endl;
        // cout << veS[i] << endl;
        // if(veS[i][idx] == '0'){
        //     cout << "0!" << endl;
        // }
        if(veS[i][idx] == '1'){
            // cout << "1!" << endl;
            mid = i;
            break;
        }
    }
    vector<string> nextS;
    // cout << "mid = " << mid << endl;
    if(mid == -1){
        return "1";
    }
    ll size = veS.size() / 2;
    if(veS.size()%2 == 1){
        size ++;
    }
    if(mid < size){
        // cout << "smallMid" << endl;
        nextS = vector<string>(veS.begin(), veS.begin() + mid);
        sort(nextS.begin(), nextS.end(), [idx](const std::string& a, const std::string& b) {
        // n文字目以降の部分文字列で比較
        return a.substr(idx) < b.substr(idx);
        });
        if(veS.size() == 1){

        }
        return "1" + solve(idx + 1, nextS);
    }
    else{
        nextS = vector<string>(veS.begin() + mid, veS.end());
        sort(nextS.begin(), nextS.end(), [idx](const std::string& a, const std::string& b) {
        // n文字目以降の部分文字列で比較
        return a.substr(idx) < b.substr(idx);
        });
        return "0" + solve(idx + 1, nextS);
    }
}

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

    sort(vecS.begin(), vecS.end());
    string ans = solve(0, vecS);
    if(ans[ans.size() - 1] == 'x'){
        cout << "No" << endl;
    }else{
        ll cnt = M;
        for(ll i = 0; i < ans.size(); i ++){
            cout << ans[i];
            cnt --;
        }
        for(ll i = cnt; cnt > 0; cnt --){
            cout << '0';
        }
        cout << endl;
    }


}