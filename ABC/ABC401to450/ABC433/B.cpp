#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using ll = long long int;
using namespace std;

ll N, maxNum;
vector<ll> listA, highestList;

int main(){
    cin >> N;
    listA.resize(N);
    for(int i = 0; i< N; i ++){
        cin >> listA[i];
    }
    for(ll i = 0; i < N; i ++){
        ll result = -1;
        for(int j = i - 1; j >= 0; j --){
            if(listA[j] > listA[i]){
                result = j + 1;
                break;
            }
        }
        cout << result << endl;

    }
}