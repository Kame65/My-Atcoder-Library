#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main(){
    ll N;
    cin >> N;
    ll fSize = 1000;
    vector<vector<ll>>field(fSize + 2, vector<ll>(fSize + 2, 0));
    for(ll i = 0; i < N; i ++){
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        field[ly + 1][lx + 1] ++;
        field[ry + 1][rx + 1] ++;
        field[ry +1][lx + 1] --;
        field[ly + 1][rx + 1] --;
    }
    for(ll y = 1; y < fSize + 1; y ++){
        for(ll x = 1; x < fSize + 1; x ++){
            field[y][x] = field[y][x - 1] + field[y][x];
        }
    }
    for(ll y = 1; y < fSize + 1; y ++){
        for(ll x = 1; x < fSize + 1; x ++){
            field[y][x] = field[y - 1][x] + field[y][x];
        }
    }
    vector<ll>results(N + 1, 0);
    for(ll y = 1; y < fSize + 1; y ++){
        for(ll x = 1; x < fSize + 1; x ++){
            results[field[y][x]] += 1;
            // cout << field[y][x] << " ";
        }
        // cout << endl;
    }
    for(ll i = 1; i <= N; i ++){
        cout << results[i] << endl;
    }
}