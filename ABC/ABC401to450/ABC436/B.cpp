#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
using ll = long long int;

ll N;
vector<vector<ll>> field;
ll countN = 0;

void ope(int x, int y, int k){//kを書く
    // cout << x << " " << y << " " << k << endl;
    if(countN == N * N){
        return;
    }
    // if(countN == 5){
    //     cout << x << " " << y << endl;
    // }
    if(field[x][y] != 0){
        ope((x + 2) % N, (N + (y - 1)) % N, k);
    }else{
        field[x][y] = k;
        // cout << "field " << x << " " << y << " " << k << endl;
        countN += 1;
        ope((N + (x - 1)) % N, (N + (y + 1)) % N, k + 1);
    }
}

int main(){
    cin >> N;

    field.resize(N);
    for(int i = 0; i < N; i ++){
        field[i].resize(N, 0);
    }

    ope(0, (N - 1) / 2, 1);

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            cout << field[i][j] << " ";
        }
        cout << endl;
    }


}