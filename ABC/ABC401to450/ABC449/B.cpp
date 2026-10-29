#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


ll H, W, Q;

void solveQ(){
    ll type;
    cin >> type;
    if(type == 1){
        ll R;
        cin >> R;
        cout << R * W << endl;;
        H -= R;
    }else{
        ll C;
        cin >> C;
        cout << C * H << endl;
        W -= C;
    }
}


int main(){
    cin >> H >> W >> Q;
    for(int i = 0; i < Q; i ++){
        solveQ();
    }
}
