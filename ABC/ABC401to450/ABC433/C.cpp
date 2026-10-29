#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using ll = long long int;
using namespace std;

ll input;
string S;
ll N;
vector<ll> listS;


int main(){
    cin >> S;

    // getline(cin, S);
    N = S.size();
    for(ll i = 0; i < N; i ++){
        listS.push_back(S.at(i) - '0');
    }
    

    ll beforeNum, afterNum;
    ll beforeCount, afterCount;
    beforeCount = 0;
    afterCount = 0;
    beforeNum = listS[0];
    afterNum = beforeNum + 1;
    ll result = 0;

    
    for(ll i = 0; i < N; i ++){
        ll num = listS[i];
        if(beforeNum == num){
            beforeCount += 1;
        }else if(afterNum == listS[i]){
            afterCount += 1;
        }else{
            result += min(beforeCount, afterCount);
            if(num == afterNum + 1){
                beforeNum = afterNum;
                afterNum = num;
                beforeCount = afterCount;
                afterCount = 1;
            }else{
                beforeNum = num;
                afterNum = num + 1;
                beforeCount = 1;
                afterCount = 0;
            }
            
        }
    }
    cout << result + min(beforeCount, afterCount) << endl;;
}