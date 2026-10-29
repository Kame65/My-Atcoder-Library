#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
using ll = long long int;

ll N, result; 
vector<ll> listA;


int main(){
    cin >> N;
    listA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> listA[i];
    }

    ll length = listA[0]; 
    ll countD = 0;
    ll idx = 0;
    while(1){
        if(length <= idx || countD >= N){
            break;
        }else{
            countD += 1;
            length = max(idx + listA[idx], length);
            // cout << length << endl;
        }
        idx ++ ;
    }
    cout << countD << endl;

}