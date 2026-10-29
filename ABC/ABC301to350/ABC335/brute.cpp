#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int N, M;
vector<int> A;
vector<vector<int>> G;
vector<bool> used;
int ans = 0;

void dfs(int v, int score){
    if(v == N){
        ans = max(ans, score);
    }

    used[v] = true;

    for(int to : G[v]){
        if(used[to]) continue;
        if(A[to] < A[v]) continue;

        if(A[to] == A[v]){
            dfs(to, score);
        }else{
            dfs(to, score + 1);
        }
    }

    used[v] = false;
}

int main(){
    cin >> N >> M;

    A.resize(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    G.assign(N + 1, {});

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    used.assign(N + 1, false);

    dfs(1, 1);

    cout << ans << endl;
}