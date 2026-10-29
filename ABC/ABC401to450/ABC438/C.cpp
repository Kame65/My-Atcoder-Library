#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

ll N;
vector<ll> vecA;
vector<vector<ll>> vecl;
vector<ll> judge;

bool judgePop(){
    if(judge.size() >= 4){
        ll last = judge.size() - 1;
        // cout << judge[last] << " " << judge[last - 1] << " "
            //  << judge[last - 2] << " " << judge[last - 3] << endl;
        
        if(judge[last] == judge[last - 1] 
            && judge[last - 2] == judge[last - 3]
            && judge[last - 1] == judge[last-2]){
            for(int i = 0; i < 4; i ++){
                // cout << "pop: " << judge[last - 1]<< endl;
                judge.pop_back();
            }
            return true;
        }
    }
    return false;
}



int main(){
    cin >> N;
    vecA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecA[i];
    }
    for(ll i = 0; i < N; i ++){
        judge.push_back(vecA[i]);
        while(true){
            if(!judgePop()){
                // cout << "judgeEnd" << endl;
                break;
            }
        }
    }


    // for(int i = 0; i < judge.size(); i ++){
    //     cout << judge[i] << " ";
    // }
    // cout <<endl;
    cout << judge.size() << endl;

}