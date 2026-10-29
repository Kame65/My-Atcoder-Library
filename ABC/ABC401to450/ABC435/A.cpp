#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
using ll = long long int;

ll N;
int main(){
    cin >> N;
    ll total = 0;
    for(int i = 0; i <= N; i ++){
        total += i;
    }
    cout << total << endl;
}