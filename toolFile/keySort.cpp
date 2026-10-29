#include <iostream>
#include <vector>
#include <algorithm>



using ll = long long int;
using namespace std;

vector<vector<ll>> myVec(10);
int main(){
    sort(myVec.begin(),myVec.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[0] < beta[0];});
}



