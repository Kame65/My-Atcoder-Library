#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;
using vl = vector<ll>;

vl counts(26, 0);

int main(){
    string S;
    cin >> S;
    for(ll i = 0; i < S.size(); i ++){
        counts[S[i] - 'a'] += 1;
    }
    ll max = counts[0];
    for(ll i = 0; i < counts.size(); i ++){
        if(counts[i] > max){
            max = counts[i];
        }
    }
    vector<char> chars;
    for(ll i = 0; i < counts.size(); i ++){
        if(counts[i] == max){
            chars.push_back(i + 'a');
        }
    }
    string resultS = "";
    for(ll i = 0; i < S.size(); i ++){
        bool canPut = true;
        for(ll j = 0; j < chars.size(); j ++){
            if(S[i] == chars[j]){
                canPut = false;
            }   
        }
        if(canPut){
            resultS.push_back(S[i]);
        }

    }
    cout << resultS << endl;

}