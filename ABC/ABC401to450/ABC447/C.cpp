#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;
using vl = vector<ll>;


string S, T;
int main(){
    cin >> S >> T;
    S.push_back('0');
    T.push_back('0');
    ll idxS = 0;
    ll idxT = 0;
    ll cnt = 0;
    while(1){
        if(S[idxS] == '0' && T[idxT] == '0'){
            break;
        }
        if(S[idxS] == T[idxT]){
            idxS ++;
            idxT ++;
        }else if(S[idxS] == 'A'){
            cnt ++;
            idxS ++;
        }else if(T[idxT] == 'A'){
            idxT ++;
            cnt ++;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;

}