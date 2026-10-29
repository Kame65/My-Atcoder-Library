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
    ll H, W;
    cin >> H >> W;
    // cout << 1000 * W/ H/ H << endl;

    if(10000 * W / H / H >= 25){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}