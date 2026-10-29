#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;


ll N, M;
vector<ll> listA, listB;
vector<long double> sumList, numList, averageList;
int main(){
    cin >> N >> M;
    listA.resize(N);
    listB.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> listA[i] >> listB[i];
    }
    sumList.resize(M, 0);
    numList.resize(M, 0);
    for(int i = 0; i < N; i ++){
        sumList[listA[i] - 1] += listB[i];
        numList[listA[i] - 1] += 1;
    }
    for(int i = 0; i < M; i ++){
        cout << sumList[i] / numList[i] << endl;
    }

}