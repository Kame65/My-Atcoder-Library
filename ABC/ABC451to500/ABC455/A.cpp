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
    ll A, B, C;
    cin >> A >> B >> C;

    if(A != B && B == C){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}