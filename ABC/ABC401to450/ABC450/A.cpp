#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
int main(){
    int N;
    cin >> N;
    for(int i = N; i > 0; i --){
        cout << i;
        if(i != 1){
            cout << ",";
        }
    }
    cout << endl;
}