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
    string str;
    cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.size(); i ++){
        if(str[i] == 'i'){
            cnt ++;
        }
        if(str[i] == 'j'){
            cnt ++;
        }
    }
    cout << cnt << endl;
}