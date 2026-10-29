#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long int;

ll N;
vector<string> results;

void makeTrueStr(int lCnt, int rCnt, string str){
    // cout << "str = " << str << endl;
    if(lCnt + rCnt == N){
        results.push_back(str);
        return;
    }else{
        if(lCnt < N / 2){
            makeTrueStr(lCnt + 1, rCnt, str + "(");
        }
        if(lCnt > rCnt){
            makeTrueStr(lCnt, rCnt + 1, str + ")");
        }
    }  
    return;

}


int main(){
    cin >> N;
    if(N % 2 != 0){
        return 0;
    }
    ll leftCnt = 0, rightCnt = 0;
    makeTrueStr(0, 0, "");

    for(int i = 0; i < results.size(); i ++){
        cout << results[i] << endl;
    }


}