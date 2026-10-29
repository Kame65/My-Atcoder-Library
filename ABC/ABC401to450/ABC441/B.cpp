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

ll N, M, Q;
int main(){
    cin >> N >> M;
    vector<char> S(N), T(M);
    for(int i = 0; i < N; i ++){
        cin >> S[i];
    }
    for(int i = 0; i < M; i ++){
        cin >> T[i];
    }

    cin >> Q;
    for(int i = 0; i < Q; i ++){
        bool inS = true, inT = true;
        string w;
        cin >> w;
        for(int j = 0; j < w.size(); j ++){
            char c = w[j];
            // cout << "c = " << c << endl;
            bool cinS = false;
            for(int k = 0; k < N; k ++){
                
                if(c == S[k]){
                    cinS = true;
                }
            }
            if(!cinS){
                inS = false;
            }
            bool cinT = false;
            for(int k = 0; k < M; k ++){
                if(c == T[k]){
                    cinT = true;
                }
            }
            if(!cinT){
                // cout << "false" << endl;
                inT = false;
            }
        }
        if(inT){
            if(inS){
                cout << "Unknown" << endl;
            }else{
                cout << "Aoki" << endl;
            }
        }else if(inS){
            cout << "Takahashi" << endl;
        }else{
            cout << "other" << endl;
        }


    }

    




}