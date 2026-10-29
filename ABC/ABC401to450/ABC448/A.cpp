#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long int;

int main(){
    int N, X;
    cin >> N >> X;
    vector<int> vecA(N);
    for(int i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(int i = 0; i < N; i ++){
        if(X > vecA[i]){
            X = vecA[i];
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
}