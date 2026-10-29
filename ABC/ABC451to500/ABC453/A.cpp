#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long int;
using vl = vector<ll>;


int main(){
    ll N;
    string S;
    cin >> N >> S;
    bool can = false;
    for(ll i = 0; i < N; i ++){
        if(S[i] != 'o'){
            can = true;
        }
        if(can){
            cout << S[i];
        }
        
    }
    cout << endl;
}