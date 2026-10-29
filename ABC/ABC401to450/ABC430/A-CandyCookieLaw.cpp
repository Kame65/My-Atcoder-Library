#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

ll A, B, C, D;

int main(){
    cin >> A >> B >> C >> D;
    bool guilty = false;
    if(A <= C){
        
        if(B <= D){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl; 
        return 0;
    }
    cout << "No" << endl;

}
