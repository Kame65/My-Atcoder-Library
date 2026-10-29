#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

ll A, B, W;

int main(){
    cin >> A >> B >> W;
    W *= 1000;
    //A * n <= W <= B * n;
    ll maxN, minN;
    maxN = -1;
    minN = 1000001;

    for(ll n = 0; n <= 1000000; n ++){
        if(A * n <= W && W <= B * n){
            if(maxN < n){
                maxN = n;
            }
            if(minN >= n){
                minN = n;
            }
        }
    }
    if(maxN >= 0){
        cout << minN << " " << maxN << endl;
    }else{
        cout << "UNSATISFIABLE" << endl;
    }


}