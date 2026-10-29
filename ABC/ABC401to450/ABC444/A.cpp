#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main(){
    string N;
    cin >> N;
    for(ll i = 0; i < N.size(); i ++){
        if(N[i] != N[0]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}