#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;


ll M, H;


int main(){
    cin >> M >> H;
    if(H % M == 0){ 
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}