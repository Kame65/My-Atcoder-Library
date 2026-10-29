#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long int;


int main(){
    ll H, B;
    cin >> H >> B;

    if(H - B > 0){
        cout << H - B << endl;
    }
    else{
        cout << 0 << endl;
    }
}