#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long int;

int main(){
    ll N;
    cin >> N;
    unordered_map<string, bool> memo;
    for(ll i = 1; i <= N; i ++){
        string name;
        cin >> name;
        if(!memo[name]){
            memo[name] = true;
            cout << i << endl;
        }

    }
}