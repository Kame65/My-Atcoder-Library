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
    int H, W;
    cin >> H >> W;

    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            if(i == 0 || i == H - 1 || j == 0 || j == W - 1){
                cout << '#';
            }else{
                cout << '.';
            }

        }
        cout << endl;
    }
}