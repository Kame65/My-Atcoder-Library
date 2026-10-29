#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <numbers>
#include <iomanip>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    long double pi = 3.1415926535897932384;
    long double d;
    cin >> d;
    d /= 2;
    
    cout << fixed << setprecision(20) << d * d * pi << endl;

}
