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
    ll X, Q;
    cin >> X >> Q;
    priority_queue<ll> small;
    priority_queue<ll, vector<ll>, greater<ll>> large;
    ll med = X;
    for(ll i = 0;i < Q; i ++){
        ll A, B;
        cin >> A >> B;
        if(A > B){
            ll pre = A;
            A = B;
            B = pre;
        }
        if(A > med){
            // cout << "both large" << endl;
            large.push(A);
            large.push(B);
            small.push(med);
            med = large.top();
            large.pop();
        }else if(B < med){
            // cout << "both small" << endl;
            small.push(A);
            small.push(B);
            large.push(med);
            med = small.top();
            small.pop();
        }else{
            small.push(A);
            large.push(B);
        }

        cout << med << endl;


    }
}