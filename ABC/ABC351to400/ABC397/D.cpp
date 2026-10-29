#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    ll N;
    cin >> N;
    // vector<ll> pow3;
    // ll idx = 1;
    
    // while(true){
    //     ll powed = idx * idx * idx;
    //     if(powed > 2 * N ){
    //         break;
    //     }
    //     pow3.push_back(powed);
    //     idx ++;

    // }
    ll x = 1, y = 1;
    ll ansX = -1, ansY = -1;
    
    while(true){
        ll pow3X = x * x * x;
        ll pow3Y = y * y * y;
        if(pow3X - pow3Y == N){
            ansX = x, ansY = y;
            break;
        }else{
            if(pow3X - pow3Y > N){
                if(x - 1 == y){
                    break;
                }
                y ++;
            }else{
                x ++;
            }

        } 
    }
    if(ansX < 0){
        cout << -1 << endl;
    }else{
        cout << ansX << " " << ansY << endl;
    }


    
}