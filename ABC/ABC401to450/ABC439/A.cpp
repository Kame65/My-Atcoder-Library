#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long int;

int main(){
    int n;
    cin >> n;
    ll result = pow(2, n) - 2 * n;
    cout << result << endl;
}
