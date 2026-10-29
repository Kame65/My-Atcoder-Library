#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;

void test(){
    ll N, D;
    cin >> N >> D;
    vector<ll> vecA(N), vecB(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N ; i ++){
        cin >> vecB[i];
    }
    ll oldDay = 0;
    ll total = 0;
    for(ll day = 0; day < N; day ++){
        while(vecB[day] > 0){
            if(vecA[oldDay] - vecB[day] >= 0){
                vecA[oldDay] -= vecB[day];
                vecB[day] = 0;
            }else{
                vecB[day] -= vecA[oldDay];
                oldDay ++;
            }
        }
        if(day - oldDay >= D){
            oldDay ++;
        }
    }
    for(ll i = oldDay; i < N; i ++){
        total += vecA[i];
    }
    cout << total << endl;
}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        test();
    }
}