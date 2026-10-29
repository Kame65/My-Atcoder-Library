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

void solveCase(){
    ll N, K;
    cin >> N >> K;
    vl vecA(N + 1);
    for(ll i = 1; i <= N; i ++){
        cin >> vecA[i];
    }

    

}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}

// 
// 3 2
// 1 2 3
// -> 3;

// 4 3
// 1 3 2 5
// -> 3