#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

ll N, Q, top;

vector<ll> vecA, totalA;

void exeQ(){
    int type;
    cin >> type;
    if(type == 1){
        ll c;
        cin >> c;
        top += c;
        top %= N;
    }else{
        ll l, r;
        cin >> l >> r;
        // cout << top + r << " totalA[top + r] = " << totalA[top + r] << endl;
        // cout << top + l - 1 << " totalA[top + l - 1] = " << totalA[top + l - 1] << endl;
        cout << totalA[top + r] - totalA[top + l - 1] << endl;
    }
}

int main(){
    cin >> N >> Q;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    totalA.resize(2 * N);
    totalA[0] = 0;
    for(ll i = 1; i < 2 *  N; i ++){
        totalA[i] = totalA[i - 1] + vecA[(i - 1) % N];
        // cout << i << ": " << totalA[i] << endl;
    }
    // cout << "totalA[9] = " << totalA[9] << endl;
    top = 0;
    for(ll i = 0; i < Q; i ++){
        exeQ();
    }
}
