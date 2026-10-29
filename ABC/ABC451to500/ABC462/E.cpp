#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;



void solveCase(){
    ll A, B, X, Y;
    cin >> A >> B >> X >> Y;
    ll chX = abs(X);
    ll chY = abs(Y);
    ll result;
        
    if(A >= B){
        if(chX > chY){
            result = (chY * 2) * B;
            // cout << "de: " << result << endl;
            if(A >= 3 * B){
                result += (chX - chY) / 2 * (4 * B);
            }else{
                result += (chX - chY) / 2 * (A + B);
            }
            // cout << "de: " << result << endl;
            if((chX - chY) % 2 == 1){
                if(A >= 3 * B){
                    result += 3 * B;
                }else{
                    result += A;
                }
                
            }

        }else if(chX == chY){
            result = (chX + chY) * B;
        }else{//chY > chX
            result = (chX * 2) * B;
            if(A >= 3 * B){
                result += (chY - chX) / 2 * (4 * B);
            }else{
                result += (chY - chX) / 2 * (A + B);
            }
            if((chY - chX) % 2 == 1){
                result += B;
            }
        }
    }else{//B > A
        if(chX > chY){
            result = (chY * 2) * A;
            // cout << "de: " << result << endl;
            if(B >= 3 * A){
                result += (chX - chY) / 2 * (4 * A);
            }else{
                result += (chX - chY) / 2 * (A + B);
            }
            // cout << "de" << result << endl;
            if((chX - chY) % 2 == 1){
                result += A;
            }
            // cout << "de" << chX << "," <<chY << endl;

        }else if(chX == chY){
            result = (chX + chY) * A;
        }else{//chY > chX
            result = (chX * 2) * A;
            if(B >= 3 * A){
                result += (chY - chX) / 2 * (4 * A);
            }else{
                result += (chY - chX) / 2 * (A + B);
            }
            
            if((chY - chX) % 2 == 1){
                if(B >= 3 * A){
                    result += 3 * A;
                }else{
                    result += B;
                }
                
            }
        }

    }
    cout << result << endl;
}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
}