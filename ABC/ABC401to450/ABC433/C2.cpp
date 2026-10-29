#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using ll = long long int;
using namespace std;

ll result;
string S;
ll N;
vector<ll> listS, CountList,NumList;


int main(){
    cin >> S;
    result = 0;

    // getline(cin, S);
    N = S.size();
    for(ll i = 0; i < N; i ++){
        listS.push_back(S.at(i) - '0');
    }
    ll numLeft = listS[0];
    ll c = 0;
    for(ll i = 0; i < N; i ++){
        ll num = listS[i];
        if(num == numLeft){
            c += 1;
        }else{
            CountList.push_back(c);
            numLeft = num;
            c = 1;
        }
    }
    CountList.push_back(c);

    numLeft = listS[0];
    ll p = 0;
    for(ll i = 0; i < N; i ++){
        ll num = listS[i];
        // cout << numLeft << ", " << num << endl;
        
        if(numLeft != num){
            if(numLeft + 1 == num){
                result += min(CountList[p], CountList[p + 1]);
                // cout << p << ", " << CountList[p] << ", " <<  CountList[p + 1] << endl;
                // cout << result << endl;
            }
            numLeft = num;
            p ++;
        }
    }
    cout << result << endl;

}