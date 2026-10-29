#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;
using vl = vector<ll>;


string S;

bool judge(ll idx){
    if(idx == S.size()){
        return false;
    }return true;
}
int main(){
    cin >> S;
    ll ia = 0, ib = 0, ic = 0;
    bool can = true;
    ll N = S.size();
    ll cnt = 0;
    while(1){
        while(S[ia] != 'A'){
            ia ++;
            if(ia == S.size()){
                can = false;
                break;
            }
        }
        while(S[ib] != 'B'){
            ib ++;
            if(ib == S.size()){
                can = false;
                break;
            }
        }
        while(S[ic] != 'C'){
            ic ++;
            if(ic == S.size()){
                can = false;
                break;
            }
        }
        if(!can){
            break;
        }
        if(ia > ib){
            ib ++;
        }else if(ib > ic){
            ic ++;
        }else{
            ia ++;
            ib ++;
            ic ++;
            cnt ++;
        }
        if(ia >= N || ib >= N || ic >= N){
            break;
        }

    }
    cout << cnt << endl;

}