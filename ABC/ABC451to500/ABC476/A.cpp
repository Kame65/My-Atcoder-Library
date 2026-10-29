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
    string S;
    cin >> S;
    if(S[S.size() - 1] == 'e'){
        cout << S << "r" << endl;
    }else{
        cout << S << "er" << endl;
    }

}
