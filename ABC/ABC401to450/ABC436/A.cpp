#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
using ll = long long int;

ll N;
string S;

int main(){
    cin >> N >> S;
    for(ll i = 0; i < N - S.size(); i ++){
        cout << "o";
    }
    cout << S << endl;
}