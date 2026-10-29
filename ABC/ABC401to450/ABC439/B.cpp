#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long int;

int main(){
    ll N;
    cin >> N;
    string str;
    map<string, int> memo;
    while(true){
        string str = to_string(N);
        if(N == 1){
            cout << "Yes" << endl;
            break;
        }else if(memo.find(str) != memo.end()){
            // cout << (memo.find(N) != memo.end()) << endl;
            cout << "No" << endl;
            break;
        }
        else{
            str = to_string(N);
            N = 0;
            for(int i = 0; i < str.length(); i ++){
                N += pow((str[i] - '0'), 2);
            }
            // cout << N << endl;
            memo[str] = 1;
        }
    }
}
