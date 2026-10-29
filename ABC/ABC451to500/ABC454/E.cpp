#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <string>

using ll = long long int;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


void solveCase(){
    ll N , A, B;
    cin >> N >> A >> B;
    if(N % 2 != 0){
        cout << "No" << endl;
        return;
    }
    if((A + B) % 2 == 0){
        cout << "No" << endl;
        return;
    } 
    vector<char> starts;
    for(ll i = 0; i < (A + 1) / 2 - 1; i ++){
        for(ll j = 0; j < N - 1; j ++){
            starts.push_back('R');
        }
        starts.push_back('D');
        for(ll j = 0; j < N - 1; j ++){
            starts.push_back('L');
        }
        starts.push_back('D');
    }
    // cout << string(starts.begin(), starts.end()) << endl;
    ll y = A;
    if(A % 2 == 0){
        y = A - 1;
    }
    for(ll x = 1; x <= N; x ++){
        if(x == N && y == N){
            break;
        }
        if(x == N){
            if(y % 2 == 1){
                starts.push_back('D');
            }
            y ++;
            if(y != N){
                starts.push_back('D');
            }
        }else if(x == B){
            starts.push_back('R');
        }else{
            if(y % 2 == 1){
                starts.push_back('D');
                starts.push_back('R');
                y ++;
            }else{
                starts.push_back('U');
                starts.push_back('R');
                y --;
            }
        }
    }
    // cout << string(starts.begin(), starts.end()) << endl;
    for(ll i = 0; i < (N - A) / 2; i ++){
        for(ll j = 0; j < N - 1; j ++){
            starts.push_back('L');
        }
        starts.push_back('D');
        for(ll j = 0; j < N - 1; j ++){
            starts.push_back('R');
        }
        if(i != (N - A) / 2 - 1){
            starts.push_back('D');
        }

    }
    cout << "Yes" << endl;
    cout << string(starts.begin(), starts.end()) << endl;


}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }

}