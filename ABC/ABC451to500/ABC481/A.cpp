#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    if(A + B > 9) cout<< 2;
    else cout << 1;
}