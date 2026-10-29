#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll N, M;
    cin >> N >> M;
    vl vecN(N + 1, 0);
    for(int i = 0; i < M; i ++){
        ll A, B;
        cin >> A >> B;
        vecN[A] ++;
        vecN[B] ++;
    }
    for(ll i = 1; i < N + 1; i ++){
        ll num = N - vecN[i] - 1;
        ll result;
        if(num < 3){
            result = 0;
        }else{
            result = num * (num - 1) * (num - 2) / 6;
        }
        cout << result << " ";
    }
    cout << endl;


}