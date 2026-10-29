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
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    for(ll i = 0; i < N; i ++){
        if(T[i] != '*' && S[i] != T[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
