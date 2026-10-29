#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
using ll = long long int;

ll N;
string str;

ll getStartA(string S){
    ll result, nextA, nextB;
    result = 0;
    nextA = 0;
    nextB = 0;
    for(ll i = 0; i < 2 * N; i ++){
        // cout << "start: i = " << i << endl;
        if(i % 2 == 0){
            // cout << "2n" << endl;
            if(S[i] != 'A'){
                while(S[nextA] != 'A'){
                    nextA ++;
                }
                S[i] = 'A';
                S[nextA] = 'B';
                result += nextA - i;
            }

        }
        if(i % 2 == 1){
            // cout << "2n + 1" << endl;
            if(S[i] != 'B'){
                while(S[nextB] != 'B'){
                    nextB ++;
                    // cout << i << " " << nextB << endl;
                }
                S[i] = 'B';
                S[nextB] = 'A';
                result += nextB - i;
            }

            
        }
        if(nextA < i){
            nextA = i;
        }
        if(nextB < i){
            nextB = i;
        }
        // cout << "startA: " << i << " " << result << " " << S << endl;
    }
    return result;
}

ll getStartB(string S){
    ll result, nextA, nextB;
    result = 0;
    nextA = 0;
    nextB = 0;
    for(ll i = 0; i < 2 * N; i ++){
        // cout << "start: i = " << i << endl;
        if(i % 2 == 1){
            // cout << "2n" << endl;
            if(S[i] != 'A'){
                while(S[nextA] != 'A'){
                    nextA ++;
                }
                S[i] = 'A';
                S[nextA] = 'B';
                result += nextA - i;
            }

        }
        if(i % 2 == 0){
            // cout << "2n + 1" << endl;
            if(S[i] != 'B'){
                while(S[nextB] != 'B'){
                    nextB ++;
                    // cout << i << " " << nextB << endl;
                }
                S[i] = 'B';
                S[nextB] = 'A';
                result += nextB - i;
            }

            
        }
        if(nextA < i){
            nextA = i;
        }
        if(nextB < i){
            nextB = i;
        }
        // cout << "startA: " << i << " " << result << " " << S << endl;
    }
    return result;
}
int main(){
    cin >> N;
    cin >> str;
    
    ll result1, result2;

    result1 = getStartA(str);
    result2 = getStartB(str);
    if(result1 < result2){
        cout << result1 << endl;
    }else{
        cout  << result2 << endl;
    }

}

