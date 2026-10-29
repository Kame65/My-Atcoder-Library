#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


void solveCase(){
    ll Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;

    //grad1: -(Px - Qx) / (Py - Qy)
    //grad2: -(Rx - Sx) / (Ry - Sy)
    //grad1 != grad2
    // cout << "test" << endl;
    // cout << Px - Qx << endl;
    // cout << -(Px - Qx) * (Ry - Sy) << endl;
    // cout << -(Rx - Sx) * (Py - Qy) << endl;
    if(Ry - Sy == 0 && Py - Qy != 0){
        cout << "Yes" << endl;
        return;
    }
    if(Py - Qy == 0 && Ry - Sy != 0){
        cout << "Yes" << endl;
        return;
    }
    if(Px - Qx == 0 && Rx - Sx != 0){
        cout << "Yes" << endl;
        return;
    }
    if(Rx - Sx == 0 && Px - Qx != 0){
        cout << "Yes" << endl;
        return;
    }
    if(Py - Qy == 0){
        if(Px + Qx == Rx + Sx){
            cout << "Yes" << endl;
            return;
        }else{
            cout << "No" << endl;
            return;
        }
    }
    

    if((Px - Qx) * (Ry - Sy) != (Rx - Sx) * (Py - Qy)){
        cout << "Yes" << endl;
        return;
    }else{
        if((Px - Qx) * (Px + Qx) + (Py - Qy) * (Py + Qy) == (Px - Qx) * (Rx + Sx) + (Py - Qy) * (Ry + Sy)){
            cout << "Yes" << endl;
            return;
        }else{
            cout << "No" << endl;
            return;
        }

    }
}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}