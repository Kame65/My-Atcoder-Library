#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

ll S, A, B, X;

int main(){
    cin >> S >> A >> B >> X;
    ll q = X / (A + B);
    ll result = q * S * A;

    if(X - ((A + B) * q) >= A){
        result += S * A;
    }else{
        result += (X - ((A + B) * q)) * S;
    }
    cout << result << endl;
}