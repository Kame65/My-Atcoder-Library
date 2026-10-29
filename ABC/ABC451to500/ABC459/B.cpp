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
    vector<string> S(N);


    for(int i = 0; i < N; i ++){
        cin >> S[i];
        // cout << "ok" << endl;

    }
    // cout << "W" << endl;;
    for(int i = 0; i < N; i ++){
        ll f = S[i][0] - 'a';
        int c;
        if(f <= 2){
            c = 2;
        }else if(f <= 5){
            c = 3;
        }
        else if(f <= 8){
            c = 4;
        }else if(f <= 11){
            c = 5;
        }else if(f <= 14){
            c = 6;
        }else if(f <= 18){
            c = 7;
        }else if(f <= 21){
            c = 8;
        }else{
            c = 9;
        }
        cout << c;
    }
    cout << endl;
}