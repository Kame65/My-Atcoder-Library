#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



int main(){
    int N, M;
    cin >> N >> M;
    if(N < 10){
        if(N % 2 == 1){
            if(N != 1){
                if(N == M){
                    cout << "Yes" << endl;
                    return 0;
                }
            }else if(M == 7){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}