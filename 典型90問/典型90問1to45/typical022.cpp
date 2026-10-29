#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

ll cutCnt = 0;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll gcdab = __gcd(a, b);
    ll gcdabc = __gcd(gcdab, c);

    cout << a / gcdabc + b / gcdabc + c / gcdabc - 3 << endl;
}