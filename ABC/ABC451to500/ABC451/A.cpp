#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long int;

int main(){
    string S;
    cin >> S;
    if(S.size() % 5 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}