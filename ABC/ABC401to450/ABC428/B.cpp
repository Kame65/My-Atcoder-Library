#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
using ll = long long int;

ll N, K;
string str;
map<string, int> strMap;


int main(){
    cin >> N >> K >> str;
    ll right, left;
    right = K - 1;
    left = 0;
    while(left < N - K + 1){
        strMap[str.substr(left, K)] += 1;
        left ++;
    }
    ll max = 0;
    for(auto e : strMap){
        if(e.second > max){
            max = e.second;
        }
    }
    cout << max << endl;
    for(auto e: strMap){
        if(e.second == max){
            cout << e.first << " ";
        }
    }
    cout << endl;

}
