#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

ll N, M, sumA;
vector<ll> listA;

int main(){
    cin >> N >> M;
    listA.resize(N);
    for(int i = 0; i < N; i ++){
        cin >> listA[i];
    }
    
    sumA = 0;
    for(int i = 0; i < N; i ++){
        sumA += listA[i];  
    }

    ll target = sumA - M;
    for(int i = 0; i < N; i ++){
        if(listA[i] == target){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}
