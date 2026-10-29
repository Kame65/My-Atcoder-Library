#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using ll = long long int;
using namespace std;

ll N, M;
vector<ll> listA;
vector<ll> powedList, listAtoM;

void makePowedList(){
    powedList.resize(11);
    powedList[0] = 1;
    for(int i = 1; i < 11; i ++){
        powedList[i] = (powedList[i - 1] * 10) % M;
    }
}

int main(){
    
    cin >> N >> M;
    makePowedList();
    listA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> listA[i];
    }
    listAtoM.resize(M, 0);

    
    for(ll i = 0; i < N; i ++){
        ll num = listA[i];
        listAtoM[num % M] += 1;
    }
    ll result = 0;
    for(ll i = 0; i < N; i ++){
        int size = to_string(listA[i]).size();
        cout << size << endl;
        
        if((M - (listA[i] % M)) % powedList[size] == 0){
            result += listAtoM[(M - (listA[i] % M)) % powedList[size]];
        }
    }
    cout << result << endl;
}