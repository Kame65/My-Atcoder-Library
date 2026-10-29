#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long int;
using namespace std;

using vl = vector<ll>;
using vvl = vector<vl>;

vector<vector<bool>> canPair;
vvl vecA;
vector<bool> used;
ll N, M;
vl results;

void culcTotal(int n, int person, ll total){
    total += vecA[person][n];
    // cout << "n = " << n << ", person = " << person << ", total = " << total << endl;
    if(n == N){
        results.push_back(total);
        return;
    }
    used[person] = true;
    for(ll i = 1; i <= N; i ++){
        if(!used[i] && canPair[person][i]){
            culcTotal(n + 1, i, total);
        }
    }
    used[person] = false;
}


int main(){
    cin >> N;
    vecA = vvl(N + 1, vl(N + 1, 0));
    for(ll i = 1; i <= N; i ++){
        for(ll j = 1; j <= N; j ++){
            cin >> vecA[i][j];
        }
    }
    cin >> M;
    canPair = vector<vector<bool>>(N + 1, vector<bool>(N + 1, true));
    for(ll i = 0; i < M; i ++){
        ll x, y;
        cin >> x >> y;
        canPair[x][y] = false;
        canPair[y][x] = false;
    }
    used = vector<bool>(N + 1, false);
    culcTotal(0, 0, 0);
    ll ans = -1;
    if(results.size() > 0){
        ans = *min_element(results.begin(), results.end());
    }
    
    cout << ans << endl;


    
}