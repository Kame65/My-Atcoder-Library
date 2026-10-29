#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


ll P, Q, X, Y;
int main(){
    cin >> P >> Q >> X >> Y;
    if(P <= X && X <= P + 99){
        if(Q <= Y && Y <= Q + 99){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}