#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
using ll = long long int;



ll A, B, C;
vector<ll> listABC(3);
int main(){
    for(int i = 0;i < 3; i ++){
        cin >> listABC[i];
    }
    sort(listABC.begin(), listABC.end());

    for(int i = 2; i >= 0; i --){
        cout << listABC[i];
    }
    cout << endl;

}

