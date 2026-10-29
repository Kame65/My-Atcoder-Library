#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include<tuple>
using namespace std;
using ll = long long int;

ll N, M;
vector<ll> listR, listC;
map<ll, bool> myMap;

int main(){
    ll result = 0;
    cin >> N >> M;
    listR.resize(M);
    listC.resize(M);
    for(ll i = 0; i < M; i ++){
        cin >> listR[i] >> listC[i];
    }

    for(ll i = 0; i < M; i ++){
        int r = listR[i];
        int c = listC[i];
        if(myMap.find(r * N + c) == myMap.end() && myMap.find((r + 1) * N + c) == myMap.end() && 
                myMap.find(r * N + c + 1) == myMap.end() && myMap.find((r + 1) * N + c + 1) == myMap.end()){
            myMap[r * N + c] = true;
            myMap[(r + 1) * N + c] = true;
            myMap[r * N + c + 1] = true;
            myMap[(r + 1) * N + c + 1] = true;
            result += 1;
        }
    }
    cout << result << endl;


}
