#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    ll N, K;
    cin >> N >> K;
    ll total = 0;
    ll year = -1;
    while(total < K){
        total += N;
        year ++;
        N += 1;
    }

    cout << year << endl;
}