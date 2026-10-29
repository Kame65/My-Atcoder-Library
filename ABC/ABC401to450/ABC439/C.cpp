#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
using ll = long long int;

unordered_map<ll, bool> results, trash;
vector<ll> squares;



ll N;



int main(){
    cin >> N;

    for(ll i = 1; i <= N + 10; i ++){
        ll num = i * i;
        squares.push_back(num);
    }

    ll idxX = 0;
    ll idxY;
    while(true){//root(N)
        // cout << squares[idxX] << endl;
        if(squares[idxX] > N){
            break;
        }
        idxY = idxX + 1;
        while(true){//root(N)
            ll result = squares[idxX] + squares[idxY];
            if(result > N){
                break;
            }
            else if(results.find(result) != results.end()){
                results.erase(result);
                trash[result] = true;
            }
            else if(trash.find(result) == trash.end()){
                results[result] = true;
            }
            idxY ++;
        }
        idxX ++;
    }

    if(results.size() > 0){
        cout << results.size() << endl;
        vector<ll>resultVec;
        for (auto p: results) {
            ll key = p.first;
            resultVec.push_back(key);
        }
        sort(resultVec.begin(), resultVec.end());
        for(ll i = 0; i < resultVec.size(); i ++){
            cout << resultVec[i] << " ";
        }
        cout << endl;
    }else{
        cout << 0 << endl;
    }

    

}