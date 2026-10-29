#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;
using vl = vector<ll>;

int main(){
    int N, M;
    cin >> N >> M;
    int max = N / 2 + N % 2;
    if(max >= M){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}