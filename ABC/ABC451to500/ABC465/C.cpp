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

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vvl listA(N, vl(3));
    for(ll i = 0; i < N; i ++){
        listA[i][0] = i + 1;
        listA[i][1] = i - 1;
        listA[i][2] = i + 1;
    }
    ll leftIdx = 0;
    for(ll i = 0; i < N; i ++){
        if(S[i] == 'o'){
            listA[i][2] = - 1;

            for(int j = 1; j <= 2; j ++){
                if(listA[leftIdx][j] == -1){
                    listA[leftIdx][j] = i + 1;
                    if(i < N - 1){
                        listA[i + 1][1] = leftIdx;
                    }
                    break;
                    
                }
            }
            // listA[leftIdx][1] = i + 1;
            leftIdx = i;
            
        }
        // cout << "OK" << i << endl;
    }
    // cout << "f" << endl;
    ll beforeIdx = - 1;
    ll nowIdx = leftIdx;
    // cout << nowIdx << endl;
    for(ll i = 0; i < N; i ++){
        // cout << nowIdx << endl;

        cout << listA[nowIdx][0] << " ";

       
        for(int i = 1; i <= 2; i ++){
            // cout << listA[nowIdx][1] << listA[nowIdx][2] << endl;
            if(listA[nowIdx][i] != beforeIdx){
                beforeIdx = nowIdx;
                nowIdx = listA[nowIdx][i];
                break;
            }
        }
    }
    cout << endl;
    // for(int i = 0; i < N; i ++){
    //     cout << listA[i][0] << " " << listA[i][1] << " " << listA[i][2] << endl;
    // }
    // cout << endl;


    


}