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

void solveCase(){
    string S;
    cin >> S;
    vl total(26, 0);
    priority_queue<pair<ll, char>> pq;
    for(ll i = 0; i < S.size(); i ++){
        total[S[i] - 'a'] ++;
    }
    for(int i = 0; i < 26; i ++){
        pq.push(make_pair(total[i], char(i + 'a')));
    }
    string res;
    pair<ll, char> pa = pq.top();
    res += pa.second;
    pq.pop();
    pq.push(make_pair(pa.first - 1, pa.second));
    while(pq.size() > 0){
        char lastC = res[res.size() - 1];
        pair<ll, char> pa = pq.top();
        pq.pop();
        if(pa.first == 0){
            break;
        }else{
            if(pa.second == lastC){
                pair<ll, char> pa2 = pq.top();
                pq.pop();
                if(pa2.first == 0){
                    cout << "No" << endl;
                    return;
                }
                res += pa2.second;
                pq.push(make_pair(pa2.first - 1, pa2.second));
                pq.push(pa);
            }else{
                res += pa.second;
                pq.push(make_pair(pa.first - 1, pa.second));
            }
        }
        // cout << res << endl;
    }
    cout << "Yes" << endl;
    cout << res << endl;
}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}