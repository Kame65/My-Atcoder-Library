#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
using ll = long long int;
using namespace std;

ll N, M;
vector<ll> listA;
vector<unordered_map<ll, int>> listAtoM(11);//[p][q] *10^p % M == qの数
vector<ll> powedList;

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

    ll result = 0;
    for(ll i = 0; i < N; i ++){
        ll num = listA[i];
        for(int j = 1; j < 11; j ++){
            ll p = powedList[j];
            listAtoM[j][((num % M) * (p % M)) % M] += 1;
        }
    }
    for(ll i = 0; i < N; i ++){
        int size = to_string(listA[i]).size();
        result += listAtoM[size][(M - (listA[i] % M)) % M];
    }
    cout << result << endl;
}