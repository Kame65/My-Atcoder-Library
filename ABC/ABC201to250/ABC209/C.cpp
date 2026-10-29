#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


using ll = long long int;

ll N;
vector<ll> listC;
ll result = 1;
ll mod = pow(10, 9) + 7;


int main(){
    cin >> N;
    for(ll i = 0; i < N; i ++){
        ll c;
        cin >> c;
        listC.push_back(c);
    }
    sort(listC.begin(), listC.end());
    for(ll i = 0; i < N; i ++){
        if(listC[i] - i > 0){
            result *= listC[i] - i;
            result %= mod;
        }else{
            result = 0;
            break;
        }
    }
    cout << result << endl;

}
