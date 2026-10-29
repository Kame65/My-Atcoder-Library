#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>
#include <assert.h>
#include <set>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


bool judge(ll n, ll day, vector<unordered_map<ll, bool>>& memo, vvl& edges, 
        ll W, vector<string>& vecS, vector<unordered_map<ll, bool>>& noGoal){
    day %= W;
    if(vecS[n][day] != 'o'){
        return false;
    }
    if(noGoal[n][day]){
        return false;
    }
    // cout << n << ", " << day << endl;
    if(memo[n][day]){
        return true;
    }
    // cout << n << ", " << day << endl;
    memo[n][day] = true;
    for(ll i = 0; i < edges[n].size(); i ++){
        ll nextV = edges[n][i];
        if(judge(nextV, day + 1, memo, edges, W, vecS, noGoal)){
            return true;
        }
    }
    if(judge(n, day + 1, memo, edges, W, vecS, noGoal)){
        return true;
    }
    noGoal[n][day] = true;
    return false;
}

void solveCase(){
    ll N, M, W;
    cin >> N >> M;
    vvl edges(N + 1);
    for(ll i = 0; i < M; i ++){
        ll u, v;cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> W;
    vector<string> vecS(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecS[i];
    }
    // cout << "input is OK" << endl;
    vector<unordered_map<ll, bool>> visited(N + 1, unordered_map<ll, bool>());
    vector<unordered_map<ll, bool>> noGoal(N + 1, unordered_map<ll, bool>());
    for(ll i = 1; i <= N; i ++){
        // vector<unordered_map<ll, bool>> (N + 1, unordered_map<ll, bool>());
        // cout << i << endl;
        if(judge(i, 0, visited, edges, W, vecS, noGoal)){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;

    
}


int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}