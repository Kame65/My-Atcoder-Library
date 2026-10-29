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
    result = 0;
    for(int l = 0; l < N; l ++){
        for(int r = l + 1; r < N; r ++){

            ll total = 0;
            for(int k = l; k <= r; k ++){
                total += listA[k];
            }
            // cout << total << endl;

            
            //total はlからrの和
            bool oneResult = true;
            for(int k = l; k <= r; k ++){
                
                if(total % listA[k] == 0){
                    // cout << l << ", " << r << ", " << listA[k] << ", " << total << endl;
                    oneResult = false;
                }
            }
            if(oneResult){
                result ++;
                // cout << l << ", " << r << ", " << total << endl;
            }
            // cout << "true" << endl;
        }
    }
    cout << result << endl;
}