#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
using ll = long long int;

ll N, M, Q, queN, queV;
vector<ll> listX, listY;
vector<vector<ll>> canBack;
vector<bool> canGoB;

// void changeColor(ll v){
//     if(canGoB[v]){
//         return;
//     }else{
//         canGoB[v] = true;
//         for(size_t i = 0; i < canBack[v].size(); i ++){
//             changeColor(canBack[v][i]);
//         }
//     }
// }


// void solveQ(ll qNum, ll qV){

//     if(qNum == 1){
//         changeColor(qV);
//     }else{
//         if(canGoB[qV]){
//             cout << "Yes" << endl;
//         }
//     } 
// }

int main(){

    cin >> Q;
    cout << Q;
    for(ll i = 0; i < Q; i ++){
        cin >> queN >> queV;
        cout << "OK";
        // solveQ(queN, queV);
    }
}