#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
# include <cmath>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


using namespace std;

ll N;
string S;

vector<bool> isp;

void sieve() {
    ll largeN = 1e7 + 100;
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<= largeN; i++) {
    if (isp[i]) for(int j=2; i*j<=largeN; j++) isp[i*j] = false;
  }
}

ll search(ll idx, ll num, unordered_map<char, int>&myMap, unordered_map<char, bool>&usedChar, unordered_map<int, bool>&usedNum){
    if(idx == 0){
        usedChar.clear();
        usedNum.clear();
        myMap.clear();
        for(ll i = 1; i < 10; i ++){
            myMap[S[idx]] = i;
            usedChar[S[idx]] = true;
            usedNum[i] = true;
            ll result = search(idx + 1, num + i * pow(10, N - 1 - idx), myMap, usedChar, usedNum);
            if(result > 0){
                return result;
            }
            usedChar[S[idx]] = false;
            usedNum[i] = false;
        }
        return -1;
    }else if(idx < N){
        // cout << "S[idx] = " << S[idx] << endl;
        // cout << usedChar[S[idx]] << endl;
        if(usedChar[S[idx]]){
            return search(idx + 1, num + myMap[S[idx]] * pow(10, N - 1 - idx), myMap, usedChar, usedNum);
        }else{
            for(ll i = 0; i < 10; i ++){
                if(!usedNum[i]){
                    usedNum[i] = true;
                    usedChar[S[idx]] = true;
                    myMap[S[idx]] = i;
                    ll result = search(idx + 1, num + myMap[S[idx]] * pow(10, N - 1 - idx), myMap, usedChar, usedNum);
                    if(result > 0){
                        return result;
                    }
                    usedNum[i] = false;
                    usedChar[S[idx]] = false;
                }
            }
            return -1;
        }
    }else{
        if(isp[num]){
            return num;
        }else{
            return -1;
        }
    }
}

int main(){
    cin >> S;
    N = S.size();
    isp = vector<bool>(1e7 + 100 + 1, true);
    sieve();

    // cout << "OK" << endl;

    unordered_map<char, int> myMap;
    unordered_map<char, bool>usedChar;
    unordered_map<int, bool>usedNum;
    cout << search(0, 0, myMap, usedChar, usedNum) << endl;

}
