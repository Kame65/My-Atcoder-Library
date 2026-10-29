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

int main(){
    ll Q;
    cin >> Q;
    vl deck(Q);
    ll top = Q - 1;
    ll tail = 0;
    for(ll i = 0; i < Q; i ++){
        ll ti, xi;
        cin >> ti >> xi;
        if(ti == 2){
            
            deck[tail] = xi;
            tail = (tail + 1) % Q;
            
        }else if(ti == 1){
            deck[top] = xi;
            top = (top - 1 + Q) % Q;
        }else{
            cout << deck[(top + xi) % Q] << endl;;
        }
    }
    // for(ll i = 0; i < (tail + Q - top) % Q; i ++){
    //     cout << deck[(top + i + 1) % Q] << " ";
    // }
}