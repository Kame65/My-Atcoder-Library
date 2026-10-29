#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(){
    vector<string> S(2);

    cin >> S[0] >> S[1];
    if(S[0][0] == 'A' || S[0][0] == 'D'){
        if(S[1][1] == 'A' || S[1][1] == 'D'){
            cout << "No" << endl;
            return 0;
        }
    }
    if(S[1][0] == 'A' || S[1][0] == 'D'){
        if(S[0][1] == 'A' || S[0][1] == 'D'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
}