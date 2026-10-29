#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

int main(){

    int N = randInt(2, 8);

    vector<int> A(N + 1);

    for(int i = 1; i <= N; i++){
        A[i] = randInt(1, 4);
    }

    vector<pair<int,int>> edges;
    set<pair<int,int>> st;

    // 木を作る（連結にする）
    for(int i = 2; i <= N; i++){
        int p = randInt(1, i - 1);
        edges.push_back({p, i});
        st.insert({min(p,i), max(p,i)});
    }

    // ランダムに辺を追加
    int extra = randInt(0, N);

    while(extra--){
        int u = randInt(1, N);
        int v = randInt(1, N);

        if(u == v) continue;

        pair<int,int> e = {min(u,v), max(u,v)};

        if(st.count(e)) continue;

        st.insert(e);
        edges.push_back(e);
    }

    cout << N << " " << edges.size() << "\n";

    for(int i = 1; i <= N; i++){
        cout << A[i];
        if(i != N) cout << " ";
    }
    cout << "\n";

    for(auto [u,v] : edges){
        cout << u << " " << v << "\n";
    }

    return 0;
}