#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using vl = vector<int>;
using vvl = vector<vl>;




int N, M;
vl vecA, vecB, vecC;
vector<vvl> edges;
vector<vvl> memo;

struct Compare {//小さい順にする
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[2] > b[2];
    }
};

priority_queue<vector<int>, vector<vector<int>>, Compare> q;

void search1(int startV){
    priority_queue<vector<int>, vector<vector<int>>, Compare> q;//qi = {nowVi, minVi, cost}
    q.push({startV, 1, 0});
    while(q.size() > 0){
        vector<int> qi = q.top();
        q.pop();
        int nowV = qi[0], minV = qi[1], cost = qi[2];
        // cout << "StartV: " << startV << ", nowV: " << nowV << ", minV: " << minV << ", cost: " << cost << endl;
        // cout << "size = " << q.size() << endl;
        if(memo[startV][nowV][minV] < 0){
            memo[startV][nowV][minV] = cost;
        }else{
            continue;
        }
        
        int nextMinV = max(nowV, minV);
        if(nowV == startV){
            nextMinV = 1;
        }
        for(int i = 0; i < edges[nowV].size(); i ++){
            int nextV = edges[nowV][i][0];
            int nextCost = cost + edges[nowV][i][1];
            q.push({nextV, nextMinV, nextCost});
        }

    }
    
    return;
}

int main(){
    cin >> N >> M;
    vecA = vl(M);
    vecB = vl(M); 
    vecC = vl(M);
    edges = vector<vvl>(N + 1);
    memo = vector<vvl>(N + 1, vvl(N + 1, vl(N + 1, -1)));
    for(int i = 0; i < M; i ++){
        cin >> vecA[i] >> vecB[i] >> vecC[i];
        edges[vecA[i]].push_back({vecB[i], vecC[i]});
    }
    //costでsort
    for(int s = 1; s <= N; s ++){
        search1(s);
    }
    int ans = 0;
    for(int s = 1; s <= N; s++){
        for(int t = 1; t <= N; t ++){
            int before = memo[s][t][0];
            for(int k = 1; k <= N; k ++){
                // cout << "before: " << s << ", " << t << ", " << k << ", " << memo[s][t][k] << endl;
                if(memo[s][t][k] < 0){
                    memo[s][t][k] = before;
                }
                if(before >= 0 && (memo[s][t][k] > before || memo[s][t][k] == 0)){
                    memo[s][t][k] = before;
                }
                if(s == t){
                    memo[s][t][k] = 0;
                }
                // cout <<"after : " << s << ", " << t << ", " << k << ", " << memo[s][t][k] << endl;
                if(memo[s][t][k] > 0){
                    ans += memo[s][t][k];
                }
                // ans += memo[s][t][k];
                before = memo[s][t][k];
            }
        }
    }
    cout << ans << endl;

    
}



