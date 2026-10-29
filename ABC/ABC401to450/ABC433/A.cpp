#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using ll = long long int;
using namespace std;

ll X, Y, Z, c;

int main(){
    cin >> X >> Y >> Z;
    while(Y * Z <= X){
        if(Y * Z == X){
            cout << "Yes" << endl;
            return 0;
        }
        X ++;
        Y ++;
    }
    cout << "No" << endl;

}