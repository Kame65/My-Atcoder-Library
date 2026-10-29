#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;


ll N, result;

int main(){
    cin >> N;
    // N = 27182818284590;
    result = 0;
    ll mod = 1000;

    while(1){
        if(mod > N){
            break;
        }
        result += (N - (mod - 1));

        mod *= 1000;
    }
    cout << result << endl;
}