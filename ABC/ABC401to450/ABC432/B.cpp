#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

ll X;
vector<ll> splitX;

int main(){
    cin >> X;
    while(X > 0){
        splitX.push_back(X % 10);
        X /= 10;
    }
    sort(splitX.begin(), splitX.end());
    for(ll i = 0; i < splitX.size(); i ++){
        if(splitX[i] > 0){
            cout << splitX[i];
            splitX[i] = -1;
            break;
        }
    }
    for(ll i = 0; i < splitX.size(); i ++){
        if(splitX[i] >= 0){
            cout << splitX[i];
        }
    }
    cout << endl;
}

