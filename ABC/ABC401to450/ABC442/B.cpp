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

int main(){
    ll Q;
    cin >> Q;
    ll vol = 0;
    bool moving = false;
    for(ll i = 0; i < Q; i ++){
        int a;
        cin >> a;
        if(a == 1){
            vol ++;
        }
        if(a == 2){
            if(vol > 0){
                vol --;
            }
        }
        if(a == 3){
            moving = !moving;
        }

        if(vol >= 3 && moving){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
    }

}